let s:cpo_save=&cpo
set cpo&vim
inoremap <silent> <Plug>(deoplete_auto_refresh) =deoplete#mappings#refresh()
inoremap <silent> <Plug>(deoplete_start_complete) =deoplete#mappings#_do_complete(g:deoplete#_context)
inoremap <silent> <Plug>(fzf-maps-i) :call fzf#vim#maps('i', fzf#vim#layout(0))
inoremap <expr> <Plug>(fzf-complete-buffer-line) fzf#vim#complete#buffer_line()
inoremap <expr> <Plug>(fzf-complete-line) fzf#vim#complete#line()
inoremap <expr> <Plug>(fzf-complete-file-ag) fzf#vim#complete#path("ag -l -g ''")
inoremap <expr> <Plug>(fzf-complete-file) fzf#vim#complete#path("find . -path '*/\.*' -prune -o -type f -print -o -type l -print | sed 's:^..::'")
inoremap <expr> <Plug>(fzf-complete-path) fzf#vim#complete#path("find . -path '*/\.*' -prune -o -print | sed '1d;s:^..::'")
inoremap <expr> <Plug>(fzf-complete-word) fzf#vim#complete#word()
inoremap <silent> <SNR>29_AutoPairsReturn =AutoPairsReturn()
inoremap <silent> <C-Tab> =UltiSnips#ListSnippets()
inoremap <silent> <S-Tab> =CleverTab#Complete('prev')
inoremap <F1> <Nop>
inoremap <Right> <Nop>
inoremap <Left> <Nop>
inoremap <Down> <Nop>
inoremap <Up> <Nop>
snoremap <silent>  c
nnoremap  h
nnoremap <NL> j
nnoremap  k
nnoremap  l
snoremap  "_c
noremap ,rc :call rtags#FindSubClasses()
noremap ,rC :call rtags#FindSuperClasses()
noremap ,rb :call rtags#JumpBack()
noremap ,rv :call rtags#FindVirtuals()
noremap ,rw :call rtags#RenameSymbolUnderCursor()
noremap ,rl :call rtags#ProjectList()
noremap ,rr :call rtags#ReindexFile()
noremap ,rs :call rtags#FindSymbols(input("Pattern? ", "", "customlist,rtags#CompleteSymbols"))
noremap ,rn :call rtags#FindRefsByName(input("Pattern? ", "", "customlist,rtags#CompleteSymbols"))
noremap ,rf :call rtags#FindRefs()
noremap ,rp :call rtags#JumpToParent()
noremap ,rT :call rtags#JumpTo(g:NEW_TAB)
noremap ,rV :call rtags#JumpTo(g:V_SPLIT)
noremap ,rS :call rtags#JumpTo(g:H_SPLIT)
noremap ,rJ :call rtags#JumpTo(g:SAME_WINDOW, { '--declaration-only' : '' })
noremap ,rj :call rtags#JumpTo(g:SAME_WINDOW)
noremap ,ri :call rtags#SymbolInfo()
nmap ,hp <Plug>GitGutterPreviewHunk
nmap ,hr <Plug>GitGutterUndoHunk:echomsg ',hr is deprecated. Use ,hu'
nmap ,hu <Plug>GitGutterUndoHunk
nmap ,hs <Plug>GitGutterStageHunk
vnoremap ,k :Sex
nnoremap ,k :Sex
nnoremap ; :
xnoremap <silent> <nop> :call UltiSnips#SaveLastVisualSelection()gvs
snoremap <silent> <nop> :call UltiSnips#ExpandSnippet()
xmap S <Plug>VSurround
vmap [% [%m'gv``
nmap [c <Plug>GitGutterPrevHunk
vmap ]% ]%m'gv``
nmap ]c <Plug>GitGutterNextHunk
vmap a% [%v]%
xmap ac <Plug>GitGutterTextObjectOuterVisual
omap ac <Plug>GitGutterTextObjectOuterPending
nmap cS <Plug>CSurround
nmap cs <Plug>Csurround
nmap ds <Plug>Dsurround
vmap gx <Plug>NetrwBrowseXVis
nmap gx <Plug>NetrwBrowseX
xmap gS <Plug>VgSurround
xmap ic <Plug>GitGutterTextObjectInnerVisual
omap ic <Plug>GitGutterTextObjectInnerPending
nnoremap j gj
nnoremap k gk
nmap ySS <Plug>YSsurround
nmap ySs <Plug>YSsurround
nmap yss <Plug>Yssurround
nmap yS <Plug>YSurround
nmap ys <Plug>Ysurround
vnoremap <silent> <Plug>NetrwBrowseXVis :call netrw#BrowseXVis()
nnoremap <silent> <Plug>NetrwBrowseX :call netrw#BrowseX(expand((exists("g:netrw_gx")? g:netrw_gx : '<cfile>')),netrw#CheckIfRemote())
nnoremap <silent> <Plug>(Man) :call man#open_page(v:count, v:count1, &filetype ==# 'man' ? expand('<cWORD>') : expand('<cword>'))
nnoremap <silent> <Plug>SurroundRepeat .
nnoremap <silent> <Plug>GitGutterPreviewHunk :GitGutterPreviewHunk
nnoremap <silent> <Plug>GitGutterUndoHunk :GitGutterUndoHunk
nnoremap <silent> <Plug>GitGutterStageHunk :GitGutterStageHunk
nnoremap <silent> <expr> <Plug>GitGutterPrevHunk &diff ? '[c' : ":\execute v:count1 . 'GitGutterPrevHunk'\"
nnoremap <silent> <expr> <Plug>GitGutterNextHunk &diff ? ']c' : ":\execute v:count1 . 'GitGutterNextHunk'\"
xnoremap <silent> <Plug>GitGutterTextObjectOuterVisual :call gitgutter#hunk#text_object(0)
xnoremap <silent> <Plug>GitGutterTextObjectInnerVisual :call gitgutter#hunk#text_object(1)
onoremap <silent> <Plug>GitGutterTextObjectOuterPending :call gitgutter#hunk#text_object(0)
onoremap <silent> <Plug>GitGutterTextObjectInnerPending :call gitgutter#hunk#text_object(1)
onoremap <silent> <Plug>(fzf-maps-o) :call fzf#vim#maps('o', fzf#vim#layout(0))
xnoremap <silent> <Plug>(fzf-maps-x) :call fzf#vim#maps('x', fzf#vim#layout(0))
nnoremap <silent> <Plug>(fzf-maps-n) :call fzf#vim#maps('n', fzf#vim#layout(0))
nnoremap <SNR>33_: :=v:count ? v:count : ''
snoremap <silent> <Del> c
snoremap <silent> <BS> c
snoremap <silent> <C-Tab> :call UltiSnips#ListSnippets()
vnoremap <F1> <Nop>
nnoremap <F1> <Nop>
nnoremap <Right> <Nop>
nnoremap <Left> <Nop>
nnoremap <Down> <Nop>
nnoremap <Up> <Nop>
imap S <Plug>ISurround
imap s <Plug>Isurround
inoremap <silent> 	 =CleverTab#Complete('start')=CleverTab#Complete('tab')=CleverTab#Complete('ultisnips')=CleverTab#Complete('omni')=CleverTab#Complete('keyword')=CleverTab#Complete('user')=CleverTab#Complete('stop')
imap  <Plug>Isurround
inoremap <silent> <nop> =UltiSnips#ExpandSnippet()
let &cpo=s:cpo_save
unlet s:cpo_save
set background=dark
set completefunc=RtagsCompleteFunc
set completeopt=menuone,noinsert
set gdefault
set helplang=en
set hidden
set ignorecase
set listchars=tab:▸\ ,eol:¬,trail:·
set makeprg=make\ -C\ ../build\ -j16
set mouse=
set omnifunc=syntaxcomplete#Complete
set ruler
set runtimepath=~/.vim/dein/repos/github.com/Shougo/vimproc.vim,~/.vim/dein/.dein,~/.vim/dein/repos/github.com/Shougo/dein.vim,~/.config/nvim,/etc/xdg/nvim,~/.local/share/nvim/site,/usr/local/share/nvim/site,/usr/share/nvim/site,/usr/share/nvim/runtime,/usr/share/nvim/site/after,/usr/local/share/nvim/site/after,~/.local/share/nvim/site/after,/etc/xdg/nvim/after,~/.config/nvim/after,~/.fzf,~/.vim/dein/.dein/after
set scrolloff=3
set shiftwidth=4
set showcmd
set showmatch
set smartcase
set spelllang=it,en
set tabstop=4
set undofile
set visualbell
set wildmode=list:longest
set window=81
" vim: set ft=vim :
