#!/usr/bin/python3


def load_data_from_bin(path: str) -> tuple:
    with open(path, 'rb') as fr:
        return tuple(
            int.from_bytes(bytes(data), 'big')
            for data in zip(*(iter(fr.read()),) * 4)
        )


def generate_init_asm(path: str, data: tuple) -> None:

    asm = '''
.global _init
.section .text.init, "ax"

_init:'''

    for address, value in enumerate(data):
        asm += f'''
        li      a4,0x{4*address:08x}
        li      a5,0x{value:08x}
        sw      a5,0(a4)'''

    asm += '\n        ret\n'

    print(asm)

    with open(path, 'w') as fw:
        fw.writelines(asm)


if __name__ == '__main__':
    data = load_data_from_bin('build/data.bin')
    generate_init_asm('build/init.S', data)
