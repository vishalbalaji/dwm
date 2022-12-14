/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int centerwindowname = 1;       /* 0 means window title is not centered */
static const unsigned int maxtitlelength = 100;       /* max length for window title */
static const Gap default_gap        = {.isgap = 1, .realgap = 10, .gappx = 10};
static const unsigned int snap      = 32;       /* snap pixel */

/* bar */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int user_bh            = 28;        /* 0 means that dwm will calculate bar height, >= 1 means dwm will user_bh as bar height */
static const int vertpad            = 5;       /* vertical padding of bar */
static const int sidepad            = 10;       /* horizontal padding of bar */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft = 1;
static const unsigned int systrayspacing = 0;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray             = 1;   /* 0 means no systray */

/* fonts */
static const char *fonts[]          = { "JetBrainsMono Nerd Font:size=10", "JoyPixels:size=10" };
static const char dmenufont[]       = "JetBrainsMono Nerd Font:size=10";

/* colors */
static const char bar_bg[]       = "#000000";

static const char norm[]       = "#7f849c";
static const char active[]        = "#cdd6f4";

static const char col_norm_border[]   = "#7f849c";
static const char col_sel_border[]    = "#cdd6f4";

static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeSel]  = { active, active,  col_sel_border  },
	[SchemeNorm] = { active, bar_bg, col_norm_border }, // Systray background
	[SchemeStatus]  = { active, bar_bg,  bar_bg  }, // Statusbar right {text,background,not used but cannot be empty}
	[SchemeTagsSel]  = { active, bar_bg,  bar_bg  }, // Tagbar left selected {text,background,not used but cannot be empty}
	[SchemeTagsNorm]  = { norm, bar_bg,  bar_bg  }, // Tagbar left unselected {text,background,not used but cannot be empty}
	[SchemeInfoSel]  = { active, bar_bg,  bar_bg  }, // infobar middle  selected {text,background,not used but cannot be empty}
	[SchemeInfoNorm]  = { active, bar_bg,  bar_bg  }, // infobar middle  unselected {text,background,not used but cannot be empty}
};

/* alpha */
static const unsigned int baralpha = 0.0 * OPAQUE;
static const unsigned int borderalpha = 1.0 * OPAQUE;
static const unsigned int alphas[][3]      = {
	/*               fg      bg        border     */
	[SchemeNorm] = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]  = { OPAQUE, baralpha, borderalpha },
	[SchemeStatus] = { OPAQUE, baralpha, borderalpha },
	[SchemeTagsSel]  = { OPAQUE, baralpha, borderalpha },
	[SchemeTagsNorm] = { OPAQUE, baralpha, borderalpha },
	[SchemeInfoSel]  = { OPAQUE, baralpha, borderalpha },
	[SchemeInfoNorm] = { OPAQUE, baralpha, borderalpha },
};

/* autostart */
static const char *const autostart[] = {
	"dwm_time", NULL,
	NULL /* terminate */
};

/* tagging */
static const char *tags[] = { "1: ???", "2: ???", "3: ???", "4: ???" };

typedef struct {
	const char *name;
	const void *cmd;
} Sp;

const char *spcmd1[] = {"kitty", "--title", "scratchpad", "--class", "scratchpad", "-o", "initial_window_width=800", "-o", "initial_window_height=530", "-o", "remember_window_size=no", NULL };
static Sp scratchpads[] = {
	/* name          cmd */
	{"scratchpad",      spcmd1},
};

static const unsigned int ulinepad	= 5;	/* horizontal padding between the underline and tag */
static const unsigned int ulinestroke	= 2;	/* thickness / height of the underline */
static const unsigned int ulinevoffset	= 0;	/* how far above the bottom of the bar the line should appear */
static const int ulineall 		= 0;	/* 1 to show underline on all tags, 0 for just the active ones */

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "firefox",         "Navigator",           NULL,           2,        0, -1 },
	{ "scratchpad",      "scratchpad",   "scratchpad",   SPTAG(0), 1, -1 },
	{ "kitty",           "kitty",        "nmtui",        0,        1, -1 },
	{ "kitty",           "kitty",        "alsamixer",    0,        1, -1 },
	{ "St",              "st",           "nmtui",        0,        1, -1 },
	{ "kitty",           "kitty",        "alsamixer",    0,        1, -1 },
	{ "St",              "st",           "alsamixer",    0,        1, -1 },
	{ "Gucharmap",       NULL,           NULL,           0,        1, -1 },
	{ "Pcmanfm",         NULL,           NULL,           0,        1, -1 },
	{ "Nitrogen",        NULL,           NULL,           0,        1, -1 },
	{ "Blueman-manager", NULL,           NULL,           0,        1, -1 },
	{ "Lxappearance",    "lxappearance", NULL,           0,        1, -1 },
	{ "Yad",             "yad",          "Attach files", 0,        1, -1 },
	{ "Yad",             "yad",          "Save",         0,        1, -1 },
	{ "Yad",             "yad",          "Password",         0,        1, -1 },
	{ "zoom",            "zoom",         "Zoom Meeting", 0,        0, -1 },
	{ "zoom",            "zoom",         "zoom",         0,        1, -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 0; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[???]",      tile },    /* first entry is default */
	{ "[???]",      NULL },    /* no layout function means floating behavior */
	{ "[???]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
/* #define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } } */

#include "movestack.c"
static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_j,      movestack,      {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,      movestack,      {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_i,      incnmaster,     {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_5,      setmfact,       {.f = +1.55} },
	{ MODKEY,                       XK_6,      setmfact,       {.f = +1.65} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
  { MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_s,      togglesticky,   {0} },
	{ MODKEY|ShiftMask,             XK_s,      togglealwaysontop, {0} },
  { MODKEY|ShiftMask,             XK_f,      togglefullscr,  {0} },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY,                             XK_grave,  togglescratch,  {.ui = 0 } },
	{ MODKEY,                             XK_7,      setborderpx,    {.i = -1 } },
	{ MODKEY,                             XK_8,      setborderpx,    {.i = +1 } },
	{ MODKEY,                             XK_9,      setborderpx,    {.i = 0 } },
	/* { MODKEY,                       XK_minus,  setgaps,        {.i = -5 } }, */
	/* { MODKEY,                       XK_equal,  setgaps,        {.i = +5 } }, */
	/* { MODKEY|ShiftMask,             XK_minus,  setgaps,        {.i = GAP_RESET } }, */
	{ MODKEY|ShiftMask,             XK_equal,  setgaps,        {.i = GAP_TOGGLE} },
  { MODKEY|ShiftMask,             XK_r,      quit,           {1} },
	TAGKEYS(                        XK_1,                      0)
  TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
};

static const char *statuscmd[] = { "sh", "-c", "notify-send -h string:x-canonical-private-synchronous:date \"???  $(date '+%A, %d %B %Y')\"", NULL };

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button1,        spawn,          {.v = statuscmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
