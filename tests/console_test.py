import pathlib
import subprocess
import sys
import tempfile

def run(text,cwd):
    return subprocess.run([sys.argv[1]],input=text.encode(),cwd=cwd,capture_output=True,timeout=3,check=True).stdout.decode('utf-8')

with tempfile.TemporaryDirectory() as cwd:
    assert run('',cwd)
    assert 'apple - 2' in run('1\n3\napple pear apple\n3\n',cwd)
    pathlib.Path(cwd,'words.txt').write_text('one two one',encoding='ascii')
    output=run('2\nwords.txt\n3\n',cwd)
    assert 'one - 2' in output and 'two - 1' in output
    assert run('1\n',cwd)
print('PASS: console/file counts, empty input and incomplete input')
