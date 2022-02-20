#!/usr/bin/python3
# the program generates an initialization assembler
# with a dump .data section of the elf file
# wykys 2022


def load_data_from_bin(path: str) -> tuple:
    with open(path, 'rb') as fr:
        return tuple(
            int.from_bytes(bytes(data), 'big')
            for data in zip(*(iter(fr.read()),) * 4)
        )


def swap32(word: int) -> int:
    return (
        ((word << 24) & 0xFF000000) |
        ((word << 8) & 0x00FF0000) |
        ((word >> 8) & 0x0000FF00) |
        ((word >> 24) & 0x000000FF)
    )


def generate_init_asm(path: str, data: tuple) -> None:

    asm = '''
.global _init
.section .text.init, "ax"

_init:'''

    for address, value in enumerate(data):
        asm += f'''
        li      t0,0x{swap32(address * 4):08x}
        li      t1,0x{swap32(value):08x}
        sw      t1,0(t0)'''

    asm += '\n        ret\n'

    with open(path, 'w') as fw:
        fw.writelines(asm)


if __name__ == '__main__':

    data = load_data_from_bin('build/data.bin')
    generate_init_asm('build/init.S', data)
