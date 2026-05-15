import typing
from typing import Any
from abc import ABC, abstractmethod


class DataProcessor(ABC):
    def __init__(self):
        self.rank = 0
        self.data: list[Any] = []
        self.tot = 0
        self.rem = 0
        self.name = ""

    @abstractmethod
    def validate(self, data: Any) -> bool:
        pass

    @abstractmethod
    def ingest(self, data: Any) -> None:
        pass

    def output(self) -> tuple[int, str]:
        data0 = self.data[0]
        del self.data[0]
        self.rem -= 1
        rank0 = self.rank
        self.rank += 1
        return (rank0, str(data0))


class NumericProcessor(DataProcessor):
    def __init__(self):
        super().__init__()
        self.name = "Numeric processor"

    def validate(self, dt: int | float | list[int] | list[float]) -> bool:
        if isinstance(dt, int) or isinstance(dt, float):
            return True
        elif isinstance(dt, list):
            for i in range(len(dt)):
                if not isinstance(dt[i], int) and not isinstance(dt[i], float):
                    return False
            return True
        else:
            return False

    def ingest(self, data: int | float | list[int] | list[float]) -> None:
        if self.validate(data):
            if isinstance(data, list):
                new_data = list()
                for i in range(len(data)):
                    new_data.append(str(data[i]))
                    self.tot += 1
                    self.rem += 1
                self.data.extend(new_data)
            else:
                self.data.append(str(data))
                self.tot += 1
                self.rem += 1
        else:
            raise Exception(f"Can't process {data}")


class TextProcessor(DataProcessor):
    def __init__(self):
        super().__init__()
        self.name = "Text processor"

    def validate(self, data: str | list[str]) -> bool:
        if isinstance(data, str):
            return True
        elif isinstance(data, list):
            for i in range(len(data)):
                if not isinstance(data[i], str):
                    return False
            return True
        else:
            return False

    def ingest(self, data: str | list[str]) -> None:
        if self.validate(data):
            if isinstance(data, list):
                new_data = list()
                for i in range(len(data)):
                    new_data.append(data[i])
                    self.tot += 1
                    self.rem += 1
                self.data.extend(new_data)
            else:
                self.data.append(str(data))
                self.tot += 1
                self.rem += 1
        else:
            raise Exception(f"Can't process {data}")


class LogProcessor(DataProcessor):
    def __init__(self):
        super().__init__()
        self.name = "Log processor"

    def validate(self, data: list | dict) -> bool:
        if isinstance(data, dict):
            return True
        elif isinstance(data, list):
            for i in range(len(data)):
                if not isinstance(data[i], dict):
                    return False
            return True
        else:
            return False

    def ingest(self, data: list | dict) -> None:
        if self.validate(data):
            if isinstance(data, list):
                new_data = list()
                for i in range(len(data)):
                    new_data.append(data[i])
                    self.tot += 1
                    self.rem += 1
                self.data.extend(new_data)
            else:
                self.data.append(data)
                self.tot += 1
                self.rem += 1
        else:
            raise Exception(f"Can't process {data}")


class DataStream():
    def __init__(self):
        self.reg_proc: list[DataProcessor] = []

    def register_processor(self, proc: DataProcessor) -> None:
        if isinstance(proc, DataProcessor):
            self.reg_proc.append(proc)
            print(f"{proc.name} has been regitered")
        else:
            print(f"Error. {proc} is not a processor")

    def process_stream(self, stream: list[typing.Any]) -> None:
        if len(stream) == 0:
            raise Exception("No elements in the data stream")
        else:
            for y in stream[:]:
                z = 0
                for x in self.reg_proc:
                    try:
                        x.ingest(y)
                        stream.remove(y)
                        break
                    except Exception:
                        z += 1
                    if z == len(self.reg_proc):
                        print(f"Unable to process {y}")

    def print_processors_stats(self) -> None:
        print("== DataStream statistics ==")
        if not self.reg_proc:
            print("No processor found, no data")
        else:
            for i in range(len(self.reg_proc)):
                print(f"{self.reg_proc[i].name}: total {self.reg_proc[i].tot},"
                      f"remaining {self.reg_proc[i].rem} on processor")
                # print(self.reg_proc[i].data)


def main():
    print("=== Code Nexus - Data Stream ===")
    print("Initialize Data Stream...")
    data_stream = DataStream()
    data_stream.print_processors_stats()
    print()
    print("Registering Numeric Processor")
    num_p = NumericProcessor()
    data_stream.register_processor(num_p)
    print()
    data = [[{'log_level': 'WARNING',
              'log_message': 'Telnet access! Use ssh instead'},
             {'log_level': 'INFO', 'log_message': 'User wil is connected'}],
            "Hello world", [3.14, -1, 2.71], 42, ['Hi', 'five']]
    # print(f"\n{data}\n")
    print(f"Send first batch of data on stream: {data}")
    data_stream.process_stream(data)
    print()
    print("Registering other data processor: 1 Text and 1 Log processor")
    txt_p = TextProcessor()
    log_p = LogProcessor()
    data_stream.register_processor(txt_p)
    data_stream.register_processor(log_p)
    print()
    data_stream.print_processors_stats()
    print()
    print("Send the same batch again")
    data = [[{'log_level': 'WARNING',
              'log_message': 'Telnet access! Use ssh instead'},
             {'log_level': 'INFO', 'log_message': 'User wil is connected'}],
            "Hello world", [3.14, -1, 2.71], 42, ['Hi', 'five']]
    data_stream.process_stream(data)
    print()
    data_stream.print_processors_stats()
    print()
    print("Consume some elements from the data processors: "
          "3 Numeric, 2 Text, 1 Log")
    for _ in range(3):
        data_stream.reg_proc[0].output()
    for _ in range(2):
        data_stream.reg_proc[1].output()
    data_stream.reg_proc[2].output()
    data_stream.print_processors_stats()


if __name__ == "__main__":
    main()
