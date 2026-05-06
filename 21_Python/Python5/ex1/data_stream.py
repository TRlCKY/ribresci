from typing import Any, typing
from abc import ABC, abstractmethod


class DataProcessor(ABC):
    def __init__(self):
        self.rank = list()
        self.data = list()

    @abstractmethod
    def validate(self, data: Any) -> bool:
        pass

    @abstractmethod
    def ingest(self, data: Any) -> None:
        pass

    def output(self) -> tuple[int, str]:
        rank0 = self.rank[0]
        data0 = self.data[0]
        del self.rank[0]
        del self.data[0]
        return (rank0, str(data0))


class NumericProcessor(DataProcessor):
    def __init__(self):
        super().__init__()

    def validate(self, data: int | float | list) -> bool:
        if isinstance(data, int) or isinstance(data, float):
            return True
        elif isinstance(data, list):
            for i in range(len(data)):
                if not isinstance(data[i], int) or isinstance(data[i], float):
                    return False
            return True
        else:
            return False

    def ingest(self, data: int | float | list) -> None:
        if self.validate(data):
            if isinstance(data, list):
                new_data = list()
                new_rank = list()
                for i in range(len(data)):
                    new_data.append(str(data[i]))
                    x = i + len(self.data)
                    new_rank.append(x)
                self.data.extend(new_data)
                self.rank.extend(new_rank)
            else:
                self.data.append(str(data))
                x = len(self.data)
                self.rank.append(x)
        else:
            raise Exception("Improper numeric data")


class TextProcessor(DataProcessor):
    def __init__(self):
        super().__init__()

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
                new_rank = list()
                for i in range(len(data)):
                    new_data.append(data[i])
                    x = i + len(self.data)
                    new_rank.append(x)
                self.data.extend(new_data)
                self.rank.extend(new_rank)
            else:
                self.data.append(str(data))
                x = len(self.data)
                self.rank.append(x)
        else:
            raise Exception("Improper text data")


class LogProcessor(DataProcessor):
    def __init__(self):
        super().__init__()

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
                new_rank = list()
                for i in range(len(data)):
                    new_data.append(data[i])
                    x = i + len(self.data)
                    new_rank.append(x)
                self.data.extend(new_data)
                self.rank.extend(new_rank)
            else:
                self.data.append(data)
                x = len(self.data)
                self.rank.append(x)
        else:
            raise Exception("Improper log data")


class DataStream(DataProcessor):
    def __init__(self):
        super().__init__()
        self.reg_proc = list[DataProcessor]
        self.tot_num = 0
        self.tot_txt = 0
        self.tot_log = 0
        self.rem_num = 0
        self.rem_txt = 0
        self.rem_log = 0

    # metodo che registra i processori che potranno gestire i dati in
    # process_stream
    def register_processor(self, proc: DataProcessor) -> None:
        if isinstance(proc, DataProcessor):
            self.reg_proc.append(proc)
            print(f"{proc.capitalize()} has been regitered")
        else:
            print(f"Error. {proc} is not a processor")

    # metodo che analizza gli elementi in stream e decide a quale
    # processore in register_processor inviare quei dati. con un messaggio
    # di errore se nessuno di loro puo
    def process_stream(self, stream: list[typing.Any]) -> None:
        if len(stream) == 0:
            raise Exception("No elements in the data stream")
        else:
            x = len(stream)
            for i in range(x):
                print()
                # controlla la lista di processori se possono fare ingest
                # e se nessuno puo manda un errore

    def print_processors_stats(self) -> None:
        print("== DataStream statistics ==")
        if not self.data:
            print("No processor found, no data")
        else:
            if self.tot_num > 0:
                print(f"Numeric Processor: total {self.tot_num},"
                      f"remaining {self.rem_num} on processor")
            if self.tot_txt > 0:
                print(f"Text Processor: total {self.tot_txt},"
                      f"remaining {self.rem_txt} on processor")
            if self.tot_log > 0:
                print(f"Log Processor: total {self.tot_log},"
                      f"remaining {self.rem_log} on processor")


def main():
    print("=== Code Nexus - Data Stream ===")
    print("Initialize Data Stream...")
    data_stream = DataStream()
    data_stream.printrocessors_stats()
    print()
    print("Registering Numeric Processor")
    num_p = NumericProcessor()
    data_stream.register_processor(num_p)
    data = [[{'log_level': 'WARNING',
              'log_message': 'Telnet access! Use ssh instead'},
            {'log_level': 'INFO', 'log_message': 'User wil is connected'}],
             "Hello world", [3.14, -1, 2.71], 42, ['Hi', 'five']]
    for i in range(len(data)):
        data_stream.process_stream(data)


if __name__ == "__main__":
    main()
