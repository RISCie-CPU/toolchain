#include "ascii.h"

const uint8_t ASCII[128][CHAR_Y_SIZE] = {
    { 0x0, 0x0, 0x1e, 0x12, 0x12, 0x12, 0x12, 0x1e, 0x0,  0x0  }, //   0    00    NUL    NULL character
    { 0x0, 0x0, 0x1e, 0x12, 0x12, 0x12, 0x12, 0x1e, 0x0,  0x0  }, //   1    01    SOH    Start of Header
    { 0x0, 0x0, 0x1e, 0x12, 0x12, 0x12, 0x12, 0x1e, 0x0,  0x0  }, //   2    02    STX    Start of Text
    { 0x0, 0x0, 0x1e, 0x12, 0x12, 0x12, 0x12, 0x1e, 0x0,  0x0  }, //   3    03    ETX    End of Text
    { 0x0, 0x0, 0x1e, 0x12, 0x12, 0x12, 0x12, 0x1e, 0x0,  0x0  }, //   4    04    EOT    End of Transmission
    { 0x0, 0x0, 0x1e, 0x12, 0x12, 0x12, 0x12, 0x1e, 0x0,  0x0  }, //   5    05    ENQ    Enquiry
    { 0x0, 0x0, 0x1e, 0x12, 0x12, 0x12, 0x12, 0x1e, 0x0,  0x0  }, //   6    06    ACK    Acknowledge
    { 0x0, 0x0, 0x1e, 0x12, 0x12, 0x12, 0x12, 0x1e, 0x0,  0x0  }, //   7    07    BEL    Bell
    { 0x0, 0x0, 0x1e, 0x12, 0x12, 0x12, 0x12, 0x1e, 0x0,  0x0  }, //   8    08    BS     Backspace
    { 0x0, 0x0, 0x1e, 0x12, 0x12, 0x12, 0x12, 0x1e, 0x0,  0x0  }, //   9    09    HT     Horizontal Tab
    { 0x0, 0x0, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0  }, //  10    0a    LF     Line feed
    { 0x0, 0x0, 0x1e, 0x12, 0x12, 0x12, 0x12, 0x1e, 0x0,  0x0  }, //  11    0b    VT     Vertical Tab
    { 0x0, 0x0, 0x1e, 0x12, 0x12, 0x12, 0x12, 0x1e, 0x0,  0x0  }, //  12    0c    FF     Form Feed
    { 0x0, 0x0, 0x1e, 0x12, 0x12, 0x12, 0x12, 0x1e, 0x0,  0x0  }, //  13    0d    CR     Carriage return
    { 0x0, 0x0, 0x1e, 0x12, 0x12, 0x12, 0x12, 0x1e, 0x0,  0x0  }, //  14    0e    SO     Shift Out
    { 0x0, 0x0, 0x1e, 0x12, 0x12, 0x12, 0x12, 0x1e, 0x0,  0x0  }, //  15    0f    SI     Shift In
    { 0x0, 0x0, 0x1e, 0x12, 0x12, 0x12, 0x12, 0x1e, 0x0,  0x0  }, //  16    10    DLE    Data Link Escape
    { 0x0, 0x0, 0x1e, 0x12, 0x12, 0x12, 0x12, 0x1e, 0x0,  0x0  }, //  17    11    DC1    Device Control (XOn)
    { 0x0, 0x0, 0x1e, 0x12, 0x12, 0x12, 0x12, 0x1e, 0x0,  0x0  }, //  18    12    DC2    Device Control
    { 0x0, 0x0, 0x1e, 0x12, 0x12, 0x12, 0x12, 0x1e, 0x0,  0x0  }, //  19    13    DC3    Device Control (XOff)
    { 0x0, 0x0, 0x1e, 0x12, 0x12, 0x12, 0x12, 0x1e, 0x0,  0x0  }, //  20    14    DC4    Device Control
    { 0x0, 0x0, 0x1e, 0x12, 0x12, 0x12, 0x12, 0x1e, 0x0,  0x0  }, //  21    15    NAK    Negative Acknowledge
    { 0x0, 0x0, 0x1e, 0x12, 0x12, 0x12, 0x12, 0x1e, 0x0,  0x0  }, //  22    16    SYN    Synchronous Idle
    { 0x0, 0x0, 0x1e, 0x12, 0x12, 0x12, 0x12, 0x1e, 0x0,  0x0  }, //  23    17    ETB    End of Transmission Block
    { 0x0, 0x0, 0x1e, 0x12, 0x12, 0x12, 0x12, 0x1e, 0x0,  0x0  }, //  24    18    CAN    Cancel
    { 0x0, 0x0, 0x1e, 0x12, 0x12, 0x12, 0x12, 0x1e, 0x0,  0x0  }, //  25    19    EM     End of Medium
    { 0x0, 0x0, 0x1e, 0x12, 0x12, 0x12, 0x12, 0x1e, 0x0,  0x0  }, //  26    1a    SUB    Substitute
    { 0x0, 0x0, 0x1e, 0x12, 0x12, 0x12, 0x12, 0x1e, 0x0,  0x0  }, //  27    1b    ESC    Escape
    { 0x0, 0x0, 0x1e, 0x12, 0x12, 0x12, 0x12, 0x1e, 0x0,  0x0  }, //  28    1c    FS     File Separator
    { 0x0, 0x0, 0x1e, 0x12, 0x12, 0x12, 0x12, 0x1e, 0x0,  0x0  }, //  29    1d    GS     Group Separator
    { 0x0, 0x0, 0x1e, 0x12, 0x12, 0x12, 0x12, 0x1e, 0x0,  0x0  }, //  30    1e    RS     Record Separator
    { 0x0, 0x0, 0x1e, 0x12, 0x12, 0x12, 0x12, 0x1e, 0x0,  0x0  }, //  31    1f    US     Unit Separator
    { 0x0, 0x0, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0  }, //  32    20    SP     (mezera)
    { 0x0, 0x0, 0x0,  0x2,  0x2,  0x2,  0x0,  0x2,  0x0,  0x0  }, //  33    21    !
    { 0x0, 0x0, 0x0,  0xa,  0xa,  0x0,  0x0,  0x0,  0x0,  0x0  }, //  34    22    "
    { 0x0, 0x0, 0x0,  0x14, 0x3e, 0x14, 0x3e, 0x14, 0x0,  0x0  }, //  35    23    #
    { 0x0, 0x0, 0x8,  0x3c, 0x2,  0x1c, 0x20, 0x1e, 0x8,  0x0  }, //  36    24    $
    { 0x0, 0x0, 0x0,  0x22, 0x10, 0x8,  0x4,  0x22, 0x0,  0x0  }, //  37    25    %
    { 0x0, 0x0, 0x0,  0xc,  0x12, 0x2c, 0x12, 0x2c, 0x0,  0x0  }, //  38    26    &
    { 0x0, 0x0, 0x6,  0x4,  0x2,  0x0,  0x0,  0x0,  0x0,  0x0  }, //  39    27    '
    { 0x0, 0x0, 0x4,  0x2,  0x2,  0x2,  0x2,  0x2,  0x4,  0x0  }, //  40    28    (
    { 0x0, 0x0, 0x2,  0x4,  0x4,  0x4,  0x4,  0x4,  0x2,  0x0  }, //  41    29    )
    { 0x0, 0x0, 0x0,  0x24, 0x18, 0x7e, 0x18, 0x24, 0x0,  0x0  }, //  42    2a    *
    { 0x0, 0x0, 0x0,  0x8,  0x8,  0x3e, 0x8,  0x8,  0x0,  0x0  }, //  43    2b    +
    { 0x0, 0x0, 0x0,  0x0,  0x0,  0x0,  0x0,  0x4,  0x2,  0x0  }, //  44    2c    ,
    { 0x0, 0x0, 0x0,  0x0,  0x0,  0xe,  0x0,  0x0,  0x0,  0x0  }, //  45    2d    -
    { 0x0, 0x0, 0x0,  0x0,  0x0,  0x0,  0x0,  0x2,  0x0,  0x0  }, //  46    2e    .
    { 0x0, 0x0, 0x0,  0x20, 0x10, 0x8,  0x4,  0x2,  0x0,  0x0  }, //  47    2f    /
    { 0x0, 0x0, 0x1c, 0x22, 0x22, 0x22, 0x22, 0x1c, 0x0,  0x0  }, //  48    30    0
    { 0x0, 0x0, 0x10, 0x18, 0x10, 0x10, 0x10, 0x38, 0x0,  0x0  }, //  49    31    1
    { 0x0, 0x0, 0x1c, 0x22, 0x20, 0x18, 0x4,  0x3e, 0x0,  0x0  }, //  50    32    2
    { 0x0, 0x0, 0x1c, 0x22, 0x10, 0x20, 0x22, 0x1c, 0x0,  0x0  }, //  51    33    3
    { 0x0, 0x0, 0x10, 0x18, 0x14, 0x12, 0x3e, 0x10, 0x0,  0x0  }, //  52    34    4
    { 0x0, 0x0, 0x3e, 0x2,  0x1e, 0x20, 0x22, 0x1c, 0x0,  0x0  }, //  53    35    5
    { 0x0, 0x0, 0x18, 0x4,  0x1e, 0x22, 0x22, 0x1c, 0x0,  0x0  }, //  54    36    6
    { 0x0, 0x0, 0x3e, 0x20, 0x10, 0x8,  0x8,  0x8,  0x0,  0x0  }, //  55    37    7
    { 0x0, 0x0, 0x1c, 0x22, 0x1c, 0x22, 0x22, 0x1c, 0x0,  0x0  }, //  56    38    8
    { 0x0, 0x0, 0x1c, 0x22, 0x22, 0x3c, 0x10, 0x8,  0x4,  0x0  }, //  57    39    9
    { 0x0, 0x0, 0x0,  0x0,  0x2,  0x0,  0x2,  0x0,  0x0,  0x0  }, //  58    3a    :
    { 0x0, 0x0, 0x0,  0x0,  0x0,  0x4,  0x0,  0x4,  0x2,  0x0  }, //  59    3b    ;
    { 0x0, 0x0, 0x0,  0x8,  0x4,  0x2,  0x4,  0x8,  0x0,  0x0  }, //  60    3c    <
    { 0x0, 0x0, 0x0,  0x0,  0xe,  0x0,  0xe,  0x0,  0x0,  0x0  }, //  61    3d    =
    { 0x0, 0x0, 0x0,  0x2,  0x4,  0x8,  0x4,  0x2,  0x0,  0x0  }, //  62    3e    >
    { 0x0, 0x0, 0x0,  0x1c, 0x22, 0x18, 0x0,  0x8,  0x0,  0x0  }, //  63    3f    ?
    { 0x0, 0x0, 0x7c, 0x82, 0xba, 0xaa, 0x7a, 0x2,  0x7c, 0x0  }, //  64    40    @
    { 0x0, 0x0, 0x1c, 0x22, 0x22, 0x3e, 0x22, 0x22, 0x0,  0x0  }, //  65    41    A
    { 0x0, 0x0, 0x1e, 0x22, 0x1e, 0x22, 0x22, 0x1e, 0x0,  0x0  }, //  66    42    B
    { 0x0, 0x0, 0x1c, 0x22, 0x2,  0x2,  0x22, 0x1c, 0x0,  0x0  }, //  67    43    C
    { 0x0, 0x0, 0xe,  0x12, 0x22, 0x22, 0x22, 0x1e, 0x0,  0x0  }, //  68    44    D
    { 0x0, 0x0, 0x3e, 0x2,  0x1e, 0x2,  0x2,  0x3e, 0x0,  0x0  }, //  69    45    E
    { 0x0, 0x0, 0x3e, 0x2,  0x1e, 0x2,  0x2,  0x2,  0x0,  0x0  }, //  70    46    F
    { 0x0, 0x0, 0x18, 0x24, 0x2,  0x32, 0x22, 0x3c, 0x0,  0x0  }, //  71    47    G
    { 0x0, 0x0, 0x22, 0x22, 0x3e, 0x22, 0x22, 0x22, 0x0,  0x0  }, //  72    48    H
    { 0x0, 0x0, 0xe,  0x4,  0x4,  0x4,  0x4,  0xe,  0x0,  0x0  }, //  73    49    I
    { 0x0, 0x0, 0x30, 0x20, 0x20, 0x20, 0x22, 0x1c, 0x0,  0x0  }, //  74    4a    J
    { 0x0, 0x0, 0x22, 0x12, 0xe,  0xe,  0x12, 0x22, 0x0,  0x0  }, //  75    4b    K
    { 0x0, 0x0, 0x2,  0x2,  0x2,  0x2,  0x2,  0x3e, 0x0,  0x0  }, //  76    4c    L
    { 0x0, 0x0, 0x22, 0x36, 0x2a, 0x22, 0x22, 0x22, 0x0,  0x0  }, //  77    4d    M
    { 0x0, 0x0, 0x22, 0x26, 0x2e, 0x3a, 0x32, 0x22, 0x0,  0x0  }, //  78    4e    N
    { 0x0, 0x0, 0x1c, 0x22, 0x22, 0x22, 0x22, 0x1c, 0x0,  0x0  }, //  79    4f    O
    { 0x0, 0x0, 0x1e, 0x22, 0x22, 0x1e, 0x2,  0x2,  0x0,  0x0  }, //  80    50    P
    { 0x0, 0x0, 0x1c, 0x22, 0x22, 0x2a, 0x12, 0x2c, 0x0,  0x0  }, //  81    51    Q
    { 0x0, 0x0, 0x1e, 0x22, 0x1e, 0xa,  0x12, 0x22, 0x0,  0x0  }, //  82    52    R
    { 0x0, 0x0, 0x1c, 0x2,  0x1c, 0x20, 0x22, 0x1c, 0x0,  0x0  }, //  83    53    S
    { 0x0, 0x0, 0x3e, 0x8,  0x8,  0x8,  0x8,  0x8,  0x0,  0x0  }, //  84    54    T
    { 0x0, 0x0, 0x22, 0x22, 0x22, 0x22, 0x22, 0x1c, 0x0,  0x0  }, //  85    55    U
    { 0x0, 0x0, 0x22, 0x22, 0x22, 0x22, 0x14, 0x8,  0x0,  0x0  }, //  86    56    V
    { 0x0, 0x0, 0x22, 0x22, 0x22, 0x2a, 0x36, 0x22, 0x0,  0x0  }, //  87    57    W
    { 0x0, 0x0, 0x22, 0x14, 0x8,  0x8,  0x14, 0x22, 0x0,  0x0  }, //  88    58    X
    { 0x0, 0x0, 0x22, 0x22, 0x14, 0x8,  0x8,  0x8,  0x0,  0x0  }, //  89    59    Y
    { 0x0, 0x0, 0x3e, 0x10, 0x8,  0x8,  0x4,  0x3e, 0x0,  0x0  }, //  90    5a    Z
    { 0x0, 0x0, 0x6,  0x2,  0x2,  0x2,  0x2,  0x2,  0x6,  0x0  }, //  91    5b    [
    { 0x0, 0x0, 0x0,  0x2,  0x4,  0x8,  0x10, 0x20, 0x0,  0x0  }, //  92    5c    Back Slash
    { 0x0, 0x0, 0x6,  0x4,  0x4,  0x4,  0x4,  0x4,  0x6,  0x0  }, //  93    5d    ]
    { 0x0, 0x0, 0x4,  0xa,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0  }, //  94    5e    ^
    { 0x0, 0x0, 0x0,  0x0,  0x0,  0x0,  0x0,  0x3e, 0x0,  0x0  }, //  95    5f    _
    { 0x0, 0x2, 0x4,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0  }, //  96    60    `
    { 0x0, 0x0, 0x0,  0x1c, 0x20, 0x3c, 0x22, 0x3c, 0x0,  0x0  }, //  97    61    a
    { 0x0, 0x0, 0x2,  0x1a, 0x26, 0x22, 0x22, 0x1e, 0x0,  0x0  }, //  98    62    b
    { 0x0, 0x0, 0x0,  0x1c, 0x22, 0x2,  0x2,  0x3c, 0x0,  0x0  }, //  99    63    c
    { 0x0, 0x0, 0x20, 0x2c, 0x32, 0x22, 0x22, 0x3c, 0x0,  0x0  }, // 100    64    d
    { 0x0, 0x0, 0x0,  0x1c, 0x22, 0x3e, 0x2,  0x1c, 0x0,  0x0  }, // 101    65    e
    { 0x0, 0x0, 0x18, 0x4,  0x4,  0xe,  0x4,  0x4,  0x4,  0x0  }, // 102    66    f
    { 0x0, 0x0, 0x0,  0x38, 0x24, 0x22, 0x32, 0x2c, 0x20, 0x1c }, // 103    67    g
    { 0x0, 0x0, 0x2,  0x1a, 0x26, 0x22, 0x22, 0x22, 0x0,  0x0  }, // 104    68    h
    { 0x0, 0x0, 0x4,  0x0,  0x6,  0x4,  0x4,  0x4,  0x0,  0x0  }, // 105    69    i
    { 0x0, 0x0, 0x8,  0x0,  0xc,  0x8,  0x8,  0x8,  0x8,  0x6  }, // 106    6a    j
    { 0x0, 0x0, 0x2,  0x12, 0xa,  0x6,  0xa,  0x12, 0x0,  0x0  }, // 107    6b    k
    { 0x0, 0x0, 0x6,  0x4,  0x4,  0x4,  0x4,  0x4,  0x0,  0x0  }, // 108    6c    l
    { 0x0, 0x0, 0x0,  0x22, 0x36, 0x2a, 0x22, 0x22, 0x0,  0x0  }, // 109    6d    m
    { 0x0, 0x0, 0x0,  0xe,  0x12, 0x22, 0x22, 0x22, 0x0,  0x0  }, // 110    6e    n
    { 0x0, 0x0, 0x0,  0x1c, 0x22, 0x22, 0x22, 0x1c, 0x0,  0x0  }, // 111    6f    o
    { 0x0, 0x0, 0x0,  0xe,  0x12, 0x22, 0x22, 0x1e, 0x2,  0x2  }, // 112    70    p
    { 0x0, 0x0, 0x0,  0x38, 0x24, 0x22, 0x22, 0x3c, 0x20, 0x20 }, // 113    71    q
    { 0x0, 0x0, 0x0,  0x1a, 0x6,  0x2,  0x2,  0x2,  0x0,  0x0  }, // 114    72    r
    { 0x0, 0x0, 0x0,  0x1c, 0x2,  0x1c, 0x20, 0x1e, 0x0,  0x0  }, // 115    73    s
    { 0x0, 0x0, 0x4,  0xe,  0x4,  0x4,  0x4,  0x18, 0x0,  0x0  }, // 116    74    t
    { 0x0, 0x0, 0x0,  0x22, 0x22, 0x22, 0x24, 0x38, 0x0,  0x0  }, // 117    75    u
    { 0x0, 0x0, 0x0,  0x22, 0x22, 0x22, 0x14, 0x8,  0x0,  0x0  }, // 118    76    v
    { 0x0, 0x0, 0x0,  0x22, 0x22, 0x2a, 0x36, 0x22, 0x0,  0x0  }, // 119    77    w
    { 0x0, 0x0, 0x0,  0x22, 0x14, 0x8,  0x14, 0x22, 0x0,  0x0  }, // 120    78    x
    { 0x0, 0x0, 0x0,  0x22, 0x22, 0x32, 0x2c, 0x20, 0x10, 0xe  }, // 121    79    y
    { 0x0, 0x0, 0x0,  0x3e, 0x10, 0x8,  0x4,  0x3e, 0x0,  0x0  }, // 122    7a    z
    { 0x0, 0x0, 0x8,  0x4,  0x4,  0x2,  0x4,  0x4,  0x8,  0x0  }, // 123    7b    {
    { 0x0, 0x0, 0x2,  0x2,  0x2,  0x2,  0x2,  0x2,  0x2,  0x0  }, // 124    7c    |
    { 0x0, 0x0, 0x2,  0x4,  0x4,  0x8,  0x4,  0x4,  0x2,  0x0  }, // 125    7d    }
    { 0x0, 0x0, 0x0,  0x0,  0x4c, 0x32, 0x0,  0x0,  0x0,  0x0  }, // 126    7e    ~
    { 0x0, 0x0, 0x1e, 0x12, 0x12, 0x12, 0x12, 0x1e, 0x0,  0x0  }, // 127    7f    DEL (delete)
};
