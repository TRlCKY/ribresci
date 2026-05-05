from typing import Any
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

    def output(self) -> tuple[int, str] | None:
        rank0 = self.rank[0]
        data0 = self.data[0]
        del self.rank[0]
        del self.data[0]
        return [rank0, str(data0)]

    def check_and_add(self, data: Any) -> None:
        print(f"Processing data: {data}")
        for i in range(len(data)):
            if not isinstance(data[i], int | float):
                raise Exception("Invalid data")
        self.ingest(data)


class NumericProcessor(DataProcessor):
    def __init__(self):
        super().__init__()

    def validate(self, data: Any) -> bool:
        if isinstance(data, int) or isinstance(data, float):
            return True
        else:
            return False

    def ingest(self, data: int | float) -> None:
        self.data.extend(data)
        for _ in range(len(data)):
            i = len(self.rank)
            self.rank.append(i)


class TextProcessor(DataProcessor):
    def __init__(self):
        super().__init__()

    def validate(self, data: Any) -> bool:
        if isinstance(data, str):
            return True
        else:
            return False

    def ingest(self, data: int | float) -> None:
        print()


class LogProcessor(DataProcessor):
    def __init__(self):
        super().__init__()

    def validate(self, data: Any) -> bool:
        if isinstance(data, dict):
            return True
        else:
            return False

    def ingest(self, data: dict[list]) -> None:
        print()


def main():
    print("=== Code Nexus - Data Processor ===\n")
    num = NumericProcessor()
    txt = TextProcessor()
    log = LogProcessor()
    print("Testing Numeric Processor...")
    data = 42
    print(f" Trying to validate input '{data}': {num.validate(data)}")
    data = "Hello"
    print(f" Trying to validate input '{data}': {num.validate(data)}")
    data = "foo"
    print(f" Test invalid ingestion of string '{data}' without prior validation:")
    try:
        num.ingest(data)
    except Exception as e:
        print(f"Got error: {e}")
    try:
        array = [1, 2, 3, 4, 5]
        num.check_and_add(array)
    except Exception as e:
        print(f"Got error: {e}")
    print("Extracting 3 values...")
    for _ in range(3):
        tuple0 = num.output()
        print(f"Numeric value {tuple0[0]}: {tuple0[1]}")
    print()
    print("Testing Text Processor...")
    data = 42
    print(f" Trying to validate input '{data}': {txt.validate(data)}")
    data = "Hello"
    print(f" Trying to validate input '{data}': {txt.validate(data)}")
    
    print("Extracting 1 value...")
    tuple0 = txt.output()
    print(f"Numeric value {tuple0[0]}: {tuple0[1]}")
    print()
    print("Testing Log Processor...")



if __name__ == "__main__":
    main()
