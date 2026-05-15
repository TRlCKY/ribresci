import typing
from typing import Any, Protocol
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
        rank0 = self.rank
        data0 = self.data[0]
        self.rank += 1
        del self.data[0]
        self.rem -= 1
        return (rank0, str(data0))


class ExportPlugin(Protocol):
    def __init__(self):
        super().__init__()

    # gestisce la lista ricevuta stampandola nei formati CSV e JSON
    @abstractmethod
    def process_output(self, data: list[tuple[int, str]]) -> None:
        pass


class CSV(ExportPlugin):
    def __init__(self):
        super().__init__()

    def process_output(self, data: list[tuple[int, str]]):
        print("CSV Output:")
        csv_output = ""
        i = 0
        for element in data:
            csv_output += f"{element[1]}"
            if i != len(data) - 1:
                csv_output += ","
            i += 1
        print(csv_output)


class JSON(ExportPlugin):
    def __init__(self):
        super().__init__()

    def process_output(self, data: list[tuple[int, str]]):
        print("JSON Output")
        json_output = dict()
        for element in data:
            dict0 = {"item_" + str(element[0]): element[1]}
            json_output.update(dict0)
        print(json_output)


class NumericProcessor(DataProcessor):
    def __init__(self):
        super().__init__()
        self.name = "Numeric processor"

    def validate(self, dt: int | float | list) -> bool:
        if isinstance(dt, int) or isinstance(dt, float):
            return True
        elif isinstance(dt, list):
            for i in range(len(dt)):
                if not isinstance(dt[i], int) and not isinstance(dt[i], float):
                    return False
            return True
        else:
            return False

    def ingest(self, data: int | float | list) -> None:
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

    def validate(self, data: str | list) -> bool:
        if isinstance(data, str):
            return True
        elif isinstance(data, list):
            for i in range(len(data)):
                if not isinstance(data[i], str):
                    return False
            return True
        else:
            return False

    def ingest(self, data: str | list) -> None:
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

    # crea la lista di tuple da mandare a process_output
    def output_pipeline(self, nb: int, plugin: ExportPlugin) -> None:
        tuple_list = []
        for x in self.reg_proc:
            for _ in range(nb):
                if not x.data:
                    break
                tuple0 = x.output()
                tuple_list.append(tuple0)
            plugin.process_output(tuple_list)
            tuple_list.clear()


def main():
    print("=== Code Nexus - Data Pipeline ===")
    print("Inizialize Data Stream...\n")
    print("Registering Processors\n")
    data_stream = DataStream()
    data_stream.print_processors_stats()
    num = NumericProcessor()
    txt = TextProcessor()
    log = LogProcessor()
    data_stream.register_processor(num)
    data_stream.register_processor(txt)
    data_stream.register_processor(log)
    print()
    data = ['Hello world', [3.14, -1, 2.71], [
           {'log_level': 'WARNING',
            'log_message': 'Telnet access! Use ssh instead'},
           {'log_level': 'INFO', 'log_message': 'User wil is connected'}],
            42, ['Hi', 'five']]
    print(f"Send first batch of data on stream {data}\n")
    data_stream.process_stream(data)
    data_stream.print_processors_stats()
    print()
    print("Send 3 pocessed data from each processor to a CSV plugin:")
    csv = CSV()
    data_stream.output_pipeline(3, csv)
    print()
    data_stream.print_processors_stats()
    data = [21, ['Bruh', 'LLMs are wonderful', 'Stay healthy'], [
          {'log_level': 'ERROR', 'log_message': '500 server crash'},
          {'log_level': 'NOTICE',
           'log_message': 'Certificate expires in 10 days'}],
           [32, 42, 64, 84, 128, 168], 'World hello']
    print()
    print(f"Send another batch of data: {data}\n")
    json = JSON()
    data_stream.process_stream(data)
    data_stream.print_processors_stats()
    print()
    print("Send 5 pocessed data from each processor to a JSON plugin:")
    data_stream.output_pipeline(5, json)
    print()
    data_stream.print_processors_stats()


if __name__ == "__main__":
    main()
