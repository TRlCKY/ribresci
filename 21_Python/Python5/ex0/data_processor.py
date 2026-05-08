from typing import Any, Union
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

    def validate(self, data: Any) -> bool:
        dt = data
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

    def validate(self, data: Any) -> bool:
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

    def validate(self, data: Any) -> bool:
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


def main():
    print("=== Code Nexus - Data Processor ===\n")
    num = NumericProcessor()
    txt = TextProcessor()
    log = LogProcessor()
    print("Testing Numeric Processor...")
    print(f" Trying to validate input '42': {num.validate(42)}")
    print(f" Trying to validate input 'Hello': {num.validate('Hello')}")
    print(f" Test invalid ingestion of string 'foo' without prior"
           " validation:")
    try:
        num.ingest("foo")
    except Exception as e:
        print(f" Got error: {e}")
    try:
        array = [1, 2, 3, 4, 5]
        print(f" Processind data: {array}")
        num.ingest(array)
    except Exception as e:
        print(f" Got error: {e}")
    print(" Extracting 3 values...")
    for _ in range(3):
        tuple0 = num.output()
        print(f" Numeric value {tuple0[0]}: {tuple0[1]}")
    print()
    print("Testing Text Processor...")
    data = 42
    print(f" Trying to validate input '{data}': {txt.validate(data)}")
    data = "Hello"
    print(f" Trying to validate input '{data}': {txt.validate(data)}")
    try:
        array = ["Hello", "Nexus", "World"]
        print(f" Processing data: {array}")
        txt.ingest(array)
    except Exception as e:
        print(f" Got error: {e}")
    print(" Extracting 1 value...")
    tuple0 = txt.output()
    print(f" Text value {tuple0[0]}: {tuple0[1]}")
    print()
    print("Testing Log Processor...")
    data = "Hello"
    print(f" Trying to validate input '{data}': {log.validate(data)}")
    try:
        array = [{"log_level": "NOTICE",
                  "log_message": "Connection to server"},
                 {"log_level": "ERROR",
                  "log_message": "Unauthorized access!"}]
        print(f" Processing data: {array}")
        log.ingest(array)
    except Exception as e:
        print(f" Got error: {e}")
    print(" Extracting 2 values...")
    for _ in range(2):
        dict0 = log.output()
        print(f" Log entry {dict0[0]}: {dict0[1]}")


if __name__ == "__main__":
    main()
