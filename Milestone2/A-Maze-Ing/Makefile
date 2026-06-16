PYTHON := python3
PIP := pip
NAME := a_maze_ing.py
FILE := config.txt

install:
		$(PIP) install -r requirements.txt

run:
	 $(PYTHON) $(NAME) $(FILE)

debug:
		$(PYTHON) -m pdb $(NAME)

clean:
	find . -type d -name "__pycache__" -exec rm -rf {} +
	rm -f output_file/*
	rm -rf .mypy_cache
	rm -rf .pytest_cache

lint:
		flake8 .
		mypy . --warn-return-any \
			--warn-unused-ignores \
			--ignore-missing-imports \
			--disallow-untyped-defs \
			--check-untyped-defs

lint-strict:
		flake8 .
		mypy . --strict
