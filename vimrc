" All system-wide defaults are set in $VIMRUNTIME/debian.vim and sourced by
" the call to :runtime you can find below.  If you wish to change any of those
" settings, you should do it in this file (/etc/vim/vimrc), since debian.vim
" will be overwritten everytime an upgrade of the vim packages is performed.
" It is recommended to make changes after sourcing debian.vim since it alters
" the value of the 'compatible' option.

" This line should not be removed as it ensures that various options are
" properly set to work with the Vim-related packages available in Debian.
runtime! debian.vim

" Vim will load $VIMRUNTIME/defaults.vim if the user does not have a vimrc.
" This happens after /etc/vim/vimrc(.local) are loaded, so it will override
" any settings in these files.
" If you don't want that to happen, uncomment the below line to prevent
" defaults.vim from being loaded.
" let g:skip_defaults_vim = 1

" Uncomment the next line to make Vim more Vi-compatible
" NOTE: debian.vim sets 'nocompatible'.  Setting 'compatible' changes numerous
" options, so any other options should be set AFTER setting 'compatible'.
"set compatible

" Vim5 and later versions support syntax highlighting. Uncommenting the next
" line enables syntax highlighting by default.
syntax on

" If using a dark background within the editing area and syntax highlighting
" turn on this option as well
set background=dark

" Uncomment the following to have Vim jump to the last position when
" reopening a file
"if has("autocmd")
"  au BufReadPost * if line("'\"") > 1 && line("'\"") <= line("$") | exe "normal! g'\"" | endif
"endif

" Uncomment the following to have Vim load indentation rules and plugins
" according to the detected filetype.
"if has("autocmd")
"  filetype plugin indent on
"endif

" The following are commented out as they cause vim to behave a lot
" differently from regular Vi. They are highly recommended though.
set showcmd		" Show (partial) command in status line.
"set showmatch		" Show matching brackets.
"set ignorecase		" Do case insensitive matching
set smartcase		" Do smart case matching
"set incsearch		" Incremental search
"set autowrite		" Automatically save before commands like :next and :make
"set hidden		" Hide buffers when they are abandoned
set mouse=a		" Enable mouse usage (all modes)
set nocompatible
set number
"set autoindent
set list " affiche caracteres invisibles
set wildmenu
set visualbell
set cmdheight=2
set prompt
set expandtab " change tabulations en espaces
set lazyredraw
:let g:load_doxygen_syntax=1

" Highlight Tabs and Spaces
:highlight Tab ctermbg=darkgray guibg=darkgray
:highlight Space ctermbg=darkblue guibg=darkblue
:au BufWinEnter * let w:m2=matchadd('Tab', '\t', -1)
:au BufWinEnter * let w:m3=matchadd('Space', '\s\+$\| \+\ze\t', -1)
:set list listchars=tab:»·,trail:·
:highlight LineNr term=bold ctermfg=darkgray guifg=darkgray
:highlight OverLength ctermbg=red ctermfg=white guibg=#592929
match OverLength /\%81v.*/
" Source a global configuration file if available
:nnoremap <F8> :setl noai nocin nosi inde=<CR>

set  tabstop =4 "longueur d'une tabulation
set  softtabstop =4
set shiftwidth=4 "par défaut = 8
set smarttab

if filereadable("/etc/vim/vimrc.local")
  source /etc/vim/vimrc.local
endif

