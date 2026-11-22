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

## Instructions

```sh
make          # mandatory part -> libftprintf.a
make clean    # remove object files
make fclean   # remove object files and the library
make re       # fclean + all
```

```sh
cc main.c -L. -lftprintf -o demo        # mandatory (include "ft_printf.h")
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

### Design notes

- `INT_MIN` is handled with `-(unsigned long)n`, since `-n` would overflow.
- Width and precision values are capped while parsing to avoid `int` overflow.

## Resources

- `man 3 printf`, `man 3 stdarg`
- [How Assembly Functions Work - The Stack Explained](https://www.youtube.com/watch?v=u_-oQx_4jvo&t=328s)

### Use of AI

AI (Claude) was used to review the code, split it into mandatory and bonus
parts, and write test programs.
