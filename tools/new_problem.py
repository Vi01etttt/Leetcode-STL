import argparse
import re
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]


def slugify(title: str) -> str:
    slug = title.strip().lower()
    slug = re.sub(r"[^a-z0-9]+", "-", slug)
    return slug.strip("-")


def main() -> None:
    parser = argparse.ArgumentParser(description="Create a new LeetCode problem folder.")
    parser.add_argument("number", type=int, help="Problem number, for example: 1")
    parser.add_argument("title", help='Problem title, for example: "Two Sum"')
    parser.add_argument("--difficulty", default="TBD")
    parser.add_argument("--topics", default="TBD")
    parser.add_argument("--url", default="")
    args = parser.parse_args()

    problem_id = f"{args.number:04d}"
    problem_slug = slugify(args.title)
    problem_dir = ROOT / "problems" / f"{problem_id}-{problem_slug}"

    problem_dir.mkdir(parents=True, exist_ok=False)

    readme = f"""# {problem_id}. {args.title}

难度：{args.difficulty}  
专题：{args.topics}  
链接：{args.url}

## 题意


## 思路


## 算法步骤

1. 
2. 
3. 

## 复杂度

- 时间复杂度：
- 空间复杂度：

## 易错点

- 

## 复盘

- 一刷：
- 二刷：
- 三刷：
"""

    python_solution = "from typing import List\n\n\nclass Solution:\n    pass\n"
    cpp_solution = "#include <vector>\nusing namespace std;\n\n\nclass Solution {\npublic:\n};\n"
    notes = f"# {problem_id}. {args.title} 复盘\n\n## 解法对比\n\n\n## 识别信号\n\n\n## 下次重写检查\n\n- \n"

    (problem_dir / "README.md").write_text(readme, encoding="utf-8")
    (problem_dir / "solution.py").write_text(python_solution, encoding="utf-8")
    (problem_dir / "solution.cpp").write_text(cpp_solution, encoding="utf-8")
    (problem_dir / "solution_notes.md").write_text(notes, encoding="utf-8")

    print(problem_dir.relative_to(ROOT))


if __name__ == "__main__":
    main()
