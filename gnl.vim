let SessionLoad = 1
if &cp | set nocp | endif
let s:so_save = &g:so | let s:siso_save = &g:siso | setg so=0 siso=0 | setl so=-1 siso=-1
let v:this_session=expand("<sfile>:p")
silent only
silent tabonly
cd ~/gnlGithub
if expand('%') == '' && !&modified && line('$') <= 1 && getline(1) == ''
  let s:wipebuf = bufnr('%')
endif
set shortmess=aoO
argglobal
%argdel
$argadd get_next_line_exam2.c
edit get_next_line_exam2.c
let s:save_splitbelow = &splitbelow
let s:save_splitright = &splitright
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd w
wincmd _ | wincmd |
split
1wincmd k
wincmd w
let &splitbelow = s:save_splitbelow
let &splitright = s:save_splitright
wincmd t
let s:save_winminheight = &winminheight
let s:save_winminwidth = &winminwidth
set winminheight=0
set winheight=1
set winminwidth=0
set winwidth=1
exe 'vert 1resize ' . ((&columns * 128 + 128) / 257)
exe '2resize ' . ((&lines * 44 + 40) / 80)
exe 'vert 2resize ' . ((&columns * 128 + 128) / 257)
exe '3resize ' . ((&lines * 33 + 40) / 80)
exe 'vert 3resize ' . ((&columns * 128 + 128) / 257)
argglobal
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 52 - ((51 * winheight(0) + 39) / 78)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 52
normal! 0
wincmd w
argglobal
if bufexists("get_next_line_utils.c") | buffer get_next_line_utils.c | else | edit get_next_line_utils.c | endif
balt get_next_line_exam.c
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 63 - ((36 * winheight(0) + 22) / 44)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 63
normal! 020|
wincmd w
argglobal
if bufexists("~/libft42/ft_substr.c") | buffer ~/libft42/ft_substr.c | else | edit ~/libft42/ft_substr.c | endif
balt get_next_line.c
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 15 - ((5 * winheight(0) + 16) / 33)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 15
normal! 0
wincmd w
exe 'vert 1resize ' . ((&columns * 128 + 128) / 257)
exe '2resize ' . ((&lines * 44 + 40) / 80)
exe 'vert 2resize ' . ((&columns * 128 + 128) / 257)
exe '3resize ' . ((&lines * 33 + 40) / 80)
exe 'vert 3resize ' . ((&columns * 128 + 128) / 257)
tabnext 1
badd +44 get_next_line_exam2.c
badd +67 get_next_line.c
badd +17 get_next_line_exam.c
badd +0 test
badd +0 get_next_line_utils.c
badd +34 ~/minishell/libft/srcs/replace_copy_join_iter/no_alloc/ft_strlcat.c
badd +0 ~/libft42/ft_substr.c
if exists('s:wipebuf') && len(win_findbuf(s:wipebuf)) == 0
  silent exe 'bwipe ' . s:wipebuf
endif
unlet! s:wipebuf
set winheight=1 winwidth=20 shortmess=filnxtToOSA
let &winminheight = s:save_winminheight
let &winminwidth = s:save_winminwidth
let s:sx = expand("<sfile>:p:r")."x.vim"
if filereadable(s:sx)
  exe "source " . fnameescape(s:sx)
endif
let &g:so = s:so_save | let &g:siso = s:siso_save
doautoall SessionLoadPost
unlet SessionLoad
" vim: set ft=vim :
