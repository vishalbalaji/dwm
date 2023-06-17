/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx       = 1;   /* border pixel of windows */
static const unsigned int snap           = 32;  /* snap pixel */
static const unsigned int gappih         = 10;  /* horiz inner gap between windows */
static const unsigned int gappiv         = 10;  /* vert inner gap between windows */
static const unsigned int gappoh         = 10;  /* horiz outer gap between windows and screen edge */
static const unsigned int gappov         = 10;  /* vert outer gap between windows and screen edge */
static const int smartgaps_fact          = 1;   /* gap factor when there is only one client; 0 = no gaps, 3 = 3x outer gaps */
static const int showbar                 = 1;   /* 0 means no bar */
static const int topbar                  = 1;   /* 0 means bottom bar */
static const int bar_height              = 28;   /* 0 means derive from font, >= 1 explicit height */
static const int vertpad                 = 5;  /* vertical padding of bar */
static const int sidepad                 = 10;  /* horizontal padding of bar */
/* Status is to be shown on: -1 (all monitors), 0 (a specific monitor by index), 'A' (active monitor) */
static const int statusmon               = 'A';
static const unsigned int systrayspacing = 8;   /* systray spacing */
static const int showsystray             = 1;   /* 0 means no systray */
static const unsigned int ulinepad = 5;         /* horizontal padding between the underline and tag */
static const unsigned int ulinestroke  = 2;     /* thickness / height of the underline */
static const unsigned int ulinevoffset = 0;     /* how far above the bottom of the bar the line should appear */
static const int ulineall = 0;                  /* 1 to show underline on all tags, 0 for just the active ones */



/* Indicators: see patch/bar_indicators.h for options */
static int tagindicatortype              = INDICATOR_TOP_LEFT_SQUARE;
static int tiledindicatortype            = INDICATOR_NONE;
static int floatindicatortype            = INDICATOR_TOP_LEFT_SQUARE;
static const char *fonts[]          = { "JetBrains Mono:size=10", "JetBrainsMono Nerd Font Mono:size=14:antialias=true:autohint=true", "JoyPixels:size=10" };

#define BAR_BG     "#000000"
#define BAR_FG     "#ffffff"
#define NORM_FG    "#b3b9b8"
#define ACTIVE_FG  "#8ccf7e"

static char c000000[]                    = "#000000"; // placeholder value

static char normfgcolor[]                = BAR_FG;
static char normbgcolor[]                = BAR_BG;
static char normbordercolor[]            = NORM_FG;
static char normfloatcolor[]             = NORM_FG;

static char selfgcolor[]                 = BAR_FG;
static char selbgcolor[]                 = BAR_BG;
static char selbordercolor[]             = ACTIVE_FG;
static char selfloatcolor[]              = ACTIVE_FG;

static char titlenormfgcolor[]           = NORM_FG;
static char titlenormbgcolor[]           = BAR_BG;
static char titlenormbordercolor[]       = BAR_BG;
static char titlenormfloatcolor[]        = BAR_BG;

static char titleselfgcolor[]            = BAR_FG;
static char titleselbgcolor[]            = BAR_BG;
static char titleselbordercolor[]        = BAR_BG;
static char titleselfloatcolor[]         = BAR_BG;

static char tagsnormfgcolor[]            = NORM_FG;
static char tagsnormbgcolor[]            = BAR_BG;
static char tagsnormbordercolor[]        = BAR_BG;
static char tagsnormfloatcolor[]         = BAR_BG;

static char tagsselfgcolor[]             = ACTIVE_FG;
static char tagsselbgcolor[]             = BAR_BG;
static char tagsselbordercolor[]         = BAR_BG;
static char tagsselfloatcolor[]          = BAR_BG;

static char hidnormfgcolor[]             = NORM_FG;
static char hidselfgcolor[]              = NORM_FG;
static char hidnormbgcolor[]             = BAR_BG;
static char hidselbgcolor[]              = BAR_BG;

static char urgfgcolor[]                 = BAR_BG;
static char urgbgcolor[]                 = ACTIVE_FG;
static char urgbordercolor[]             = ACTIVE_FG;
static char urgfloatcolor[]              = ACTIVE_FG;



static const unsigned int baralpha = 0x00;
static const unsigned int borderalpha = OPAQUE;
static const unsigned int alphas[][3] = {
	/*                       fg      bg        border     */
	[SchemeNorm]         = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]          = { OPAQUE, baralpha, borderalpha },
	[SchemeTitleNorm]    = { OPAQUE, baralpha, borderalpha },
	[SchemeTitleSel]     = { OPAQUE, baralpha, borderalpha },
	[SchemeTagsNorm]     = { OPAQUE, baralpha, borderalpha },
	[SchemeTagsSel]      = { OPAQUE, baralpha, borderalpha },
	[SchemeHidNorm]      = { OPAQUE, baralpha, borderalpha },
	[SchemeHidSel]       = { OPAQUE, baralpha, borderalpha },
	[SchemeUrg]          = { OPAQUE, baralpha, borderalpha },
};

static char *colors[][ColCount] = {
	/*                       fg                bg                border                float */
	[SchemeNorm]         = { normfgcolor,      normbgcolor,      normbordercolor,      normfloatcolor },
	[SchemeSel]          = { selfgcolor,       selbgcolor,       selbordercolor,       selfloatcolor },
	[SchemeTitleNorm]    = { titlenormfgcolor, titlenormbgcolor, titlenormbordercolor, titlenormfloatcolor },
	[SchemeTitleSel]     = { titleselfgcolor,  titleselbgcolor,  titleselbordercolor,  titleselfloatcolor },
	[SchemeTagsNorm]     = { tagsnormfgcolor,  tagsnormbgcolor,  tagsnormbordercolor,  tagsnormfloatcolor },
	[SchemeTagsSel]      = { tagsselfgcolor,   tagsselbgcolor,   tagsselbordercolor,   tagsselfloatcolor },
	[SchemeHidNorm]      = { hidnormfgcolor,   hidnormbgcolor,   c000000,              c000000 },
	[SchemeHidSel]       = { hidselfgcolor,    hidselbgcolor,    c000000,              c000000 },
	[SchemeUrg]          = { urgfgcolor,       urgbgcolor,       urgbordercolor,       urgfloatcolor },
};



static const char *const autostart[] = {
	"dwm_time", NULL,
	NULL /* terminate */
};

const char *spcmd1[] = {"kitty", "--title", "scratchpad", "--class", "scratchpad", "-o", "initial_window_width=800", "-o", "initial_window_height=530", "-o", "remember_window_size=no", NULL };
static Sp scratchpads[] = {
   /* name          cmd  */
   {"scratchpad",      spcmd1},
};

/* Tags
 * In a traditional dwm the number of tags in use can be changed simply by changing the number
 * of strings in the tags array. This build does things a bit different which has some added
 * benefits. If you need to change the number of tags here then change the NUMTAGS macro in dwm.c.
 *
 * Examples:
 *
 *  1) static char *tagicons[][NUMTAGS*2] = {
 *         [DEFAULT_TAGS] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F", "G", "H", "I" },
 *     }
 *
 *  2) static char *tagicons[][1] = {
 *         [DEFAULT_TAGS] = { "•" },
 *     }
 *
 * The first example would result in the tags on the first monitor to be 1 through 9, while the
 * tags for the second monitor would be named A through I. A third monitor would start again at
 * 1 through 9 while the tags on a fourth monitor would also be named A through I. Note the tags
 * count of NUMTAGS*2 in the array initialiser which defines how many tag text / icon exists in
 * the array. This can be changed to *3 to add separate icons for a third monitor.
 *
 * For the second example each tag would be represented as a bullet point. Both cases work the
 * same from a technical standpoint - the icon index is derived from the tag index and the monitor
 * index. If the icon index is is greater than the number of tag icons then it will wrap around
 * until it an icon matches. Similarly if there are two tag icons then it would alternate between
 * them. This works seamlessly with alternative tags and alttagsdecoration patches.
 */
static char *tagicons[][NUMTAGS] =
{
	// [DEFAULT_TAGS]        = { "1", "2", "3", "4" },
	[DEFAULT_TAGS]        = { "1: ", "2: ", "3: ", "4: " },
	[ALTERNATIVE_TAGS]    = { "A", "B", "C", "D" },
	[ALT_TAGS_DECORATION] = { "<1>", "<2>", "<3>", "<4>" },
	// [DEFAULT_TAGS]        = { "1", "2", "3", "4", "5", "6", "7", "8", "9" },
	// [ALTERNATIVE_TAGS]    = { "A", "B", "C", "D", "E", "F", "G", "H", "I" },
	// [ALT_TAGS_DECORATION] = { "<1>", "<2>", "<3>", "<4>", "<5>", "<6>", "<7>", "<8>", "<9>" },
};


/* There are two options when it comes to per-client rules:
 *  - a typical struct table or
 *  - using the RULE macro
 *
 * A traditional struct table looks like this:
 *    // class      instance  title  wintype  tags mask  isfloating  monitor
 *    { "Gimp",     NULL,     NULL,  NULL,    1 << 4,    0,          -1 },
 *    { "Firefox",  NULL,     NULL,  NULL,    1 << 7,    0,          -1 },
 *
 * The RULE macro has the default values set for each field allowing you to only
 * specify the values that are relevant for your rule, e.g.
 *
 *    RULE(.class = "Gimp", .tags = 1 << 4)
 *    RULE(.class = "Firefox", .tags = 1 << 7)
 *
 * Refer to the Rule struct definition for the list of available fields depending on
 * the patches you enable.
 */
static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 *	WM_WINDOW_ROLE(STRING) = role
	 *	_NET_WM_WINDOW_TYPE(ATOM) = wintype
	 */
	RULE(.wintype  = WTYPE "DIALOG", .isfloating = 1)
	RULE(.wintype  = WTYPE "UTILITY",.isfloating = 1)
	RULE(.wintype  = WTYPE "TOOLBAR",.isfloating = 1)
	RULE(.wintype  = WTYPE "SPLASH", .isfloating = 1)
	RULE(.class    = "Pcmanfm",      .isfloating = 1)
	RULE(.class    = "Nitrogen",     .isfloating = 1)
	RULE(.class    = "Gucharmap",    .isfloating = 1)
	RULE(.class    = "Lxappearance", .instance   = "lxappearance",.isfloating = 1)
	RULE(.class    = "Yad",          .instance   = "yad",         .title      = "Attach Files",.isfloating = 1)
	RULE(.class    = "Yad",          .instance   = "yad",         .title      = "Save"        ,.isfloating = 1)
	RULE(.class    = "Yad",          .instance   = "yad",         .title      = "Password"    ,.isfloating = 1)
	RULE(.class    = "firefox",      .instance   = "Navigator",   .tags       = 2)
	RULE(.instance = "scratchpad",   .tags       = SPTAG(0),      .isfloating = 1)
};



/* Bar rules allow you to configure what is shown where on the bar, as well as
 * introducing your own bar modules.
 *
 *    monitor:
 *      -1  show on all monitors
 *       0  show on monitor 0
 *      'A' show on active monitor (i.e. focused / selected) (or just -1 for active?)
 *    bar - bar index, 0 is default, 1 is extrabar
 *    alignment - how the module is aligned compared to other modules
 *    widthfunc, drawfunc, clickfunc - providing bar module width, draw and click functions
 *    name - does nothing, intended for visual clue and for logging / debugging
 */
static const BarRule barrules[] = {
	/* monitor   bar    alignment         widthfunc                 drawfunc                clickfunc                hoverfunc                name */
	{ -1,        0,     BAR_ALIGN_LEFT,   width_tags,               draw_tags,              click_tags,              hover_tags,              "tags" },
	{ -1,        0,     BAR_ALIGN_LEFT,   width_ltsymbol,           draw_ltsymbol,          click_ltsymbol,          NULL,                    "layout" },
	{ statusmon, 0,     BAR_ALIGN_RIGHT,  width_status,             draw_status,            click_status,            NULL,                    "status" },
	{ -1,        0,     BAR_ALIGN_RIGHT,  width_systray,            draw_systray,           click_systray,           NULL,                    "systray" },
	{ -1,        0,     BAR_ALIGN_NONE,   width_wintitle,           draw_wintitle,          click_wintitle,          NULL,                    "wintitle" },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */



static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]",      tile },    /* first entry is default */
	{ "[]",      NULL },    /* no layout function means floating behavior */
	{ "[]",      monocle },
};


/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },


void toggleborder(const Arg *_)
{
	Monitor *m = selmon;
	Arg arg = { .i = 0 };
	if (m->borderpx == 0) arg.i = borderpx;
	setborderpx(&arg);
}

void togglezenmode(const Arg *arg)
{
	togglebar(arg);
	togglegaps(arg);
}

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

static const Key keys[] = {
	/* modifier                     key            function                argument */
	{ MODKEY,                             XK_b,      togglebar,        {0} },
	{ MODKEY,                             XK_z,      togglezenmode,        {0} },
	{ MODKEY,                             XK_j,      focusstack,       {.i = +1 } },
	{ MODKEY,                             XK_k,      focusstack,       {.i = -1 } },
	{ MODKEY,                             XK_i,      incnmaster,       {.i = +1 } },
	{ MODKEY|ShiftMask,                   XK_i,      incnmaster,       {.i = -1 } },
	{ MODKEY,                             XK_h,      setmfact,         {.f = -0.05} },
	{ MODKEY,                             XK_l,      setmfact,         {.f = +0.05} },
	{ MODKEY|ShiftMask,                   XK_j,      movestack,        {.i = +1 } },
	{ MODKEY|ShiftMask,                   XK_k,      movestack,        {.i = -1 } },
	{ MODKEY|ShiftMask,                   XK_Return, zoom,             {0} },
	{ MODKEY,                             XK_equal,  togglegaps,       {0} },
	{ MODKEY|ShiftMask,                   XK_equal,  defaultgaps,      {0} },
	{ MODKEY,                             XK_minus,  toggleborder,     {0} },
	{ MODKEY,                             XK_Tab,    view,             {0} },
	{ MODKEY|ShiftMask,                   XK_q,      killclient,       {0} }, // restartsig
	{ MODKEY|ShiftMask,                   XK_r,      quit,             {1} },
	{ MODKEY,                             XK_u,      focusurgent,      {0} },
	{ MODKEY,                             XK_t,      setlayout,        {.v = &layouts[0]} }, // tile layout
	{ MODKEY,                             XK_f,      setlayout,        {.v = &layouts[1]} }, // float layout
	{ MODKEY,                             XK_m,      setlayout,        {.v = &layouts[2]} }, // monocle layout
	{ MODKEY|ShiftMask,                   XK_space,  togglefloating,   {0} },
	{ MODKEY,                             XK_grave,  togglescratch,    {.ui = 0 } },
	{ MODKEY|ControlMask,                 XK_grave,  setscratch,       {.ui = 0 } },
	{ MODKEY|ShiftMask,                   XK_grave,  removescratch,    {.ui = 0 } },
	{ MODKEY|ShiftMask,                   XK_f,      togglefullscreen, {0} },
	{ MODKEY,                             XK_s,      togglesticky,     {0} },
	{ MODKEY,                             XK_0,      view,             {.ui = ~SPTAGMASK } },
	{ MODKEY|ShiftMask,                   XK_0,      tag,              {.ui = ~SPTAGMASK } },
	{ MODKEY,                             XK_comma,  focusmon,         {.i = -1 } },
	{ MODKEY,                             XK_period, focusmon,         {.i = +1 } },
	{ MODKEY|ShiftMask,                   XK_comma,  tagmon,           {.i = -1 } },
	{ MODKEY|ShiftMask,                   XK_period, tagmon,           {.i = +1 } },
	{ MODKEY|ControlMask,                 XK_comma,  tagswapmon,       {.i = +1 } },
	{ MODKEY|ControlMask,                 XK_period, tagswapmon,       {.i = -1 } },
	TAGKEYS(                        XK_1, 0)
	TAGKEYS(                        XK_2, 1)
	TAGKEYS(                        XK_3, 2)
	TAGKEYS(                        XK_4, 3)
	TAGKEYS(                        XK_5, 4)
	TAGKEYS(                        XK_6, 5)
	TAGKEYS(                        XK_7, 6)
	TAGKEYS(                        XK_8, 7)
	TAGKEYS(                        XK_9, 8)
};


static const char *statusdatecmd[] = { 
	"sh",
	"-c",
	"notify-send -h string:x-canonical-private-synchronous:date \"󰃮  $(date '+%A, %d %B %Y')\"",
	NULL
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask           button          function        argument */
	{ ClkLtSymbol,          0,                   Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,                   Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,                   Button2,        zoom,           {0} },
	{ ClkStatusText,        0,                   Button1,        spawn,          {.v = statusdatecmd } },
	{ ClkClientWin,         MODKEY,              Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,              Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,              Button3,        resizemouse,    {0} },
	{ ClkClientWin,         MODKEY|ShiftMask,    Button1,        dragmfact,      {0} },
	{ ClkTagBar,            0,                   Button1,        view,           {0} },
	{ ClkTagBar,            0,                   Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,              Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,              Button3,        toggletag,      {0} },
};




