import os

deleted_count = 0

for root, dirs, files in os.walk("."):
    for file in files:
        if file.endswith(".exe"):
            filepath = os.path.join(root, file)
            os.remove(filepath)
            print(f"Deleted: {filepath}")
            deleted_count += 1

print(f"총 {deleted_count}개의 .exe 파일을 삭제했습니다.")
