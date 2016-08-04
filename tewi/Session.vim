let SessionLoad = 1
let s:so_save = &so | let s:siso_save = &siso | set so=0 siso=0
let v:this_session=expand("<sfile>:p")
silent only
cd /mnt/ntfs_e/Projects/CPP/sdl-scratch/main_program
if expand('%') == '' && !&modified && line('$') <= 1 && getline(1) == ''
  let s:wipebuf = bufnr('%')
endif
set shortmess=aoO
badd +19 src/Video/Shader.cpp
badd +20 include/Utils/Clock.h
badd +1 src/Utils/Clock.cpp
badd +68 ~/.vim/UltiSnips/cpp.snippets
badd +1 6
badd +1 CMakeLists.txt
badd +25 include/Utils/TickTimer.h
badd +47 src/Utils/TickTimer.cpp
badd +1 src/MainGame.cpp
badd +46 include/MainGame.h
argglobal
silent! argdel *
set stal=2
edit src/MainGame.cpp
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd _ | wincmd |
split
1wincmd k
wincmd w
wincmd w
set nosplitbelow
set nosplitright
wincmd t
set winheight=1 winwidth=1
exe '1resize ' . ((&lines * 1 + 41) / 82)
exe 'vert 1resize ' . ((&columns * 155 + 156) / 312)
exe '2resize ' . ((&lines * 77 + 41) / 82)
exe 'vert 2resize ' . ((&columns * 155 + 156) / 312)
exe 'vert 3resize ' . ((&columns * 156 + 156) / 312)
argglobal
enew
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
lcd /mnt/ntfs_e/Projects/CPP/sdl-scratch/main_program
wincmd w
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
let s:l = 13 - ((12 * winheight(0) + 38) / 77)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
13
normal! 05|
lcd /mnt/ntfs_e/Projects/CPP/sdl-scratch/main_program
wincmd w
argglobal
edit /mnt/ntfs_e/Projects/CPP/sdl-scratch/main_program/include/MainGame.h
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 37 - ((33 * winheight(0) + 39) / 79)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
37
normal! 0
lcd /mnt/ntfs_e/Projects/CPP/sdl-scratch/main_program
wincmd w
exe '1resize ' . ((&lines * 1 + 41) / 82)
exe 'vert 1resize ' . ((&columns * 155 + 156) / 312)
exe '2resize ' . ((&lines * 77 + 41) / 82)
exe 'vert 2resize ' . ((&columns * 155 + 156) / 312)
exe 'vert 3resize ' . ((&columns * 156 + 156) / 312)
tabedit /mnt/ntfs_e/Projects/CPP/sdl-scratch/main_program/src/Utils/TickTimer.cpp
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd w
set nosplitbelow
set nosplitright
wincmd t
set winheight=1 winwidth=1
exe 'vert 1resize ' . ((&columns * 138 + 156) / 312)
exe 'vert 2resize ' . ((&columns * 173 + 156) / 312)
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
let s:l = 47 - ((46 * winheight(0) + 39) / 79)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
47
normal! 028|
lcd /mnt/ntfs_e/Projects/CPP/sdl-scratch/main_program
wincmd w
argglobal
edit /mnt/ntfs_e/Projects/CPP/sdl-scratch/main_program/include/Utils/TickTimer.h
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 19 - ((18 * winheight(0) + 39) / 79)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
19
normal! 0
lcd /mnt/ntfs_e/Projects/CPP/sdl-scratch/main_program
wincmd w
exe 'vert 1resize ' . ((&columns * 138 + 156) / 312)
exe 'vert 2resize ' . ((&columns * 173 + 156) / 312)
tabedit /mnt/ntfs_e/Projects/CPP/sdl-scratch/main_program/src/Utils/Clock.cpp
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd w
set nosplitbelow
set nosplitright
wincmd t
set winheight=1 winwidth=1
exe 'vert 1resize ' . ((&columns * 88 + 156) / 312)
exe 'vert 2resize ' . ((&columns * 223 + 156) / 312)
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
let s:l = 28 - ((27 * winheight(0) + 39) / 79)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
28
normal! 0
lcd /mnt/ntfs_e/Projects/CPP/sdl-scratch/main_program
wincmd w
argglobal
edit /mnt/ntfs_e/Projects/CPP/sdl-scratch/main_program/include/Utils/Clock.h
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 22 - ((21 * winheight(0) + 39) / 79)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
22
normal! 017|
lcd /mnt/ntfs_e/Projects/CPP/sdl-scratch/main_program
wincmd w
exe 'vert 1resize ' . ((&columns * 88 + 156) / 312)
exe 'vert 2resize ' . ((&columns * 223 + 156) / 312)
tabedit /mnt/ntfs_e/Projects/CPP/sdl-scratch/main_program/CMakeLists.txt
set splitbelow splitright
set nosplitbelow
set nosplitright
wincmd t
set winheight=1 winwidth=1
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
let s:l = 21 - ((20 * winheight(0) + 39) / 79)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
21
normal! 011|
lcd /mnt/ntfs_e/Projects/CPP/sdl-scratch/main_program
tabnext 4
set stal=1
if exists('s:wipebuf') && getbufvar(s:wipebuf, '&buftype') isnot# 'terminal'
  silent exe 'bwipe ' . s:wipebuf
endif
unlet! s:wipebuf
set winheight=1 winwidth=20 shortmess=filnxtToO
let s:sx = expand("<sfile>:p:r")."x.vim"
if file_readable(s:sx)
  exe "source " . fnameescape(s:sx)
endif
let &so = s:so_save | let &siso = s:siso_save
doautoall SessionLoadPost
unlet SessionLoad
" vim: set ft=vim :
