*This project has been created as part of the 42 curriculum by yabouayy.*

# ft_printf

## Description

`ft_printf` is a re-implementation of the C function `printf`. It writes to the
standard output using only `write` and `<stdarg.h>`, uses no memory
allocation, and returns the number of characters printed.

It is built as a static library, `libftprintf.a`.

### Mandatory part

Conversions: `%c` `%s` `%p` `%d` `%i` `%u` `%x` `%X` `%%`.

- A `NULL` string prints `(null)`.
- A `NULL` pointer prints `(nil)` (Linux behaviour).
- A lone `%` at the end of the format makes `ft_printf` return `-1`.

### Bonus part (`bonus/` directory)

Everything above, plus the flags `-` `0` `#` space `+`, the minimum field
width and the precision (`.`), combined in any order, e.g. `%-+8.5d`.

## Instructions

```sh
make          # mandatory part -> libftprintf.a
make bonus    # bonus part     -> libftprintf.a (replaces the mandatory build)
make clean    # remove object files
make fclean   # remove object files and the library
make re       # fclean + all
```

`make bonus` builds the library from the `bonus/*_bonus.c` files only, so the
mandatory objects are not mixed with the bonus ones. Compile flags:
`-Wall -Wextra -Werror`.

```sh
cc main.c -L. -lftprintf -o demo        # mandatory (include "ft_printf.h")
cc main.c -Ibonus -L. -lftprintf -o demo  # bonus (include "ft_printf_bonus.h")
```

### Project structure

| File | Role |
|------|------|
| `ft_printf.h` | mandatory prototypes |
| `ft_printf.c` | format loop and conversion dispatch |
| `ft_putchar.c` | `ft_putchar`, `ft_putstr` |
| `ft_putnbr.c` | `ft_putnbr` (`%d %i`), `ft_putunsigned` (`%u`) |
| `ft_puthex.c` | `ft_putbase` (generic base printer), `ft_puthex` (`%x %X`) |
| `ft_putptr.c` | `%p` |
| `bonus/ft_printf_bonus.h` | bonus prototypes and the `t_options` struct |
| `bonus/ft_printf_bonus.c` | format loop and dispatch |
| `bonus/check_format_bonus.c` | reads one `%...` specifier into `t_options` |
| `bonus/parse_functions_bonus.c` | flag and number parsing |
| `bonus/ft_numutils_bonus.c` | `ft_strlen`, `ft_abs`, `num_len`, `put_unsigned`, padding |
| `bonus/ft_putnumber_bonus.c` | shared printer for `d i u x X` |
| `bonus/ft_putnbr_bonus.c` | `%d %i` (sign handling) |
| `bonus/ft_putptr_bonus.c` | `%p` |
| `bonus/ft_putstr_bonus.c` | `%c`, `%s`, shared padding printer |

### Design notes

- `INT_MIN` is handled with `-(unsigned long)n`, since `-n` would overflow.
- Bonus number printing order: `[spaces][sign or 0x][zeros][digits][spaces]`.
- Width and precision values are capped while parsing to avoid `int` overflow.

### Testing

Both builds were compared with the real `printf` (output and return value):
the mandatory build on edge cases for every conversion, the bonus build on
5760 combinations of flags, width, precision, conversion and value.

## Resources

- `man 3 printf`, `man 3 stdarg`

### Use of AI

AI (Claude) was used to review the code, split it into mandatory and bonus
parts, and write test programs.
