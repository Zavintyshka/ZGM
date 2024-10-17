#pragma once

#ifdef USE_GLFW

#define ZGM_KEY_SPACE			32	    
#define ZGM_KEY_APOSTROPHE		39
#define ZGM_KEY_COMMA			44
#define ZGM_KEY_MINUS			45
#define ZGM_KEY_PERIOD			46 
#define ZGM_KEY_SLASH			47 
#define ZGM_KEY_0				48	    
#define ZGM_KEY_1				49	    
#define ZGM_KEY_2				50	    
#define ZGM_KEY_3				51	    
#define ZGM_KEY_4				52	    
#define ZGM_KEY_5				53	    
#define ZGM_KEY_6				54	    
#define ZGM_KEY_7				55	    
#define ZGM_KEY_8				56	    
#define ZGM_KEY_9				57	    
#define ZGM_KEY_SEMICOLON		59
#define ZGM_KEY_EQUAL			61  
#define ZGM_KEY_A				65	    
#define ZGM_KEY_B				66	    
#define ZGM_KEY_C				67	    
#define ZGM_KEY_D				68	    
#define ZGM_KEY_E				69	    
#define ZGM_KEY_F				70	    
#define ZGM_KEY_G				71	    
#define ZGM_KEY_H				72	    
#define ZGM_KEY_I				73	    
#define ZGM_KEY_J				74	    
#define ZGM_KEY_K				75	    
#define ZGM_KEY_L				76	    
#define ZGM_KEY_M				77	    
#define ZGM_KEY_N				78	    
#define ZGM_KEY_O				79	    
#define ZGM_KEY_P				80	    
#define ZGM_KEY_Q				81	    
#define ZGM_KEY_R				82	    
#define ZGM_KEY_S				83	    
#define ZGM_KEY_T				84	    
#define ZGM_KEY_U				85	    
#define ZGM_KEY_V				86	    
#define ZGM_KEY_W				87	    
#define ZGM_KEY_X				88	    
#define ZGM_KEY_Y				89	    
#define ZGM_KEY_Z				90	    
#define ZGM_KEY_LEFT_BRACKET	91	    
#define ZGM_KEY_BACKSLASH		92     
#define ZGM_KEY_RIGHT_BRACKET   93 
#define ZGM_KEY_GRAVE_ACCENT	96
#define ZGM_KEY_WORLD_1			161 /* non-US #1 */	    
#define ZGM_KEY_WORLD_2			162 /* non-US #2 */	    
#define ZGM_KEY_ESCAPE			256	    
#define ZGM_KEY_ENTER			257	    
#define ZGM_KEY_TAB				258	    
#define ZGM_KEY_BACKSPACE		259	    
#define ZGM_KEY_INSERT			260	    
#define ZGM_KEY_DELETE			261	    
#define ZGM_KEY_RIGHT			262	    
#define ZGM_KEY_LEFT			263	    
#define ZGM_KEY_DOWN			264	    
#define ZGM_KEY_UP				265	    
#define ZGM_KEY_PAGE_UP			266	    
#define ZGM_KEY_PAGE_DOWN		267	    
#define ZGM_KEY_HOME			268	    
#define ZGM_KEY_END				269	    
#define ZGM_KEY_CAPS_LOCK		280	    
#define ZGM_KEY_SCROLL_LOCK		281	    
#define ZGM_KEY_NUM_LOCK		282	    
#define ZGM_KEY_PRINT_SCREEN	283	    
#define ZGM_KEY_PAUSE			284	    
#define ZGM_KEY_F1				290	    
#define ZGM_KEY_F2				291	    
#define ZGM_KEY_F3				292	    
#define ZGM_KEY_F4				293	    
#define ZGM_KEY_F5				294	    
#define ZGM_KEY_F6				295	    
#define ZGM_KEY_F7				296	    
#define ZGM_KEY_F8				297	    
#define ZGM_KEY_F9				298	    
#define ZGM_KEY_F10				299	    
#define ZGM_KEY_F11				300	    
#define ZGM_KEY_F12				301	    
#define ZGM_KEY_F13				302	    
#define ZGM_KEY_F14				303	    
#define ZGM_KEY_F15				304	    
#define ZGM_KEY_F16				305	    
#define ZGM_KEY_F17				306	    
#define ZGM_KEY_F18				307	    
#define ZGM_KEY_F19				308	    
#define ZGM_KEY_F20				309	    
#define ZGM_KEY_F21				310	    
#define ZGM_KEY_F22				311	    
#define ZGM_KEY_F23				312	    
#define ZGM_KEY_F24				313	    
#define ZGM_KEY_F25				314	    
#define ZGM_KEY_KP_0			320	    
#define ZGM_KEY_KP_1			321	    
#define ZGM_KEY_KP_2			322	    
#define ZGM_KEY_KP_3			323	    
#define ZGM_KEY_KP_4			324	    
#define ZGM_KEY_KP_5			325	    
#define ZGM_KEY_KP_6			326	    
#define ZGM_KEY_KP_7			327	    
#define ZGM_KEY_KP_8			328	    
#define ZGM_KEY_KP_9			329	    
#define ZGM_KEY_KP_DECIMAL		330	    
#define ZGM_KEY_KP_DIVIDE		331	    
#define ZGM_KEY_KP_MULTIPLY		332	    
#define ZGM_KEY_KP_SUBTRACT		333	    
#define ZGM_KEY_KP_ADD			334	    
#define ZGM_KEY_KP_ENTER		335	    
#define ZGM_KEY_KP_EQUAL		336	    
#define ZGM_KEY_LEFT_SHIFT		340	    
#define ZGM_KEY_LEFT_CONTROL	341	    
#define ZGM_KEY_LEFT_ALT		342	    
#define ZGM_KEY_LEFT_SUPER		343	    
#define ZGM_KEY_RIGHT_SHIFT		344	    
#define ZGM_KEY_RIGHT_CONTROL   345	    
#define ZGM_KEY_RIGHT_ALT		346	    
#define ZGM_KEY_RIGHT_SUPER		347	    
#define ZGM_KEY_MENU			348	    
#define ZGM_KEY_LAST   GLFW_KEY_MENU

// Mouse Buttons
#define ZGM_MOUSE_BUTTON_1         GLFW_MOUSE_BUTTON_1
#define ZGM_MOUSE_BUTTON_2         GLFW_MOUSE_BUTTON_2
#define ZGM_MOUSE_BUTTON_3         GLFW_MOUSE_BUTTON_3
#define ZGM_MOUSE_BUTTON_4         GLFW_MOUSE_BUTTON_4
#define ZGM_MOUSE_BUTTON_5         GLFW_MOUSE_BUTTON_5
#define ZGM_MOUSE_BUTTON_6         GLFW_MOUSE_BUTTON_6
#define ZGM_MOUSE_BUTTON_7         GLFW_MOUSE_BUTTON_7
#define ZGM_MOUSE_BUTTON_8         GLFW_MOUSE_BUTTON_8
#define ZGM_MOUSE_BUTTON_LAST      GLFW_MOUSE_BUTTON_8
#define ZGM_MOUSE_BUTTON_LEFT      GLFW_MOUSE_BUTTON_1
#define ZGM_MOUSE_BUTTON_RIGHT     GLFW_MOUSE_BUTTON_2
#define ZGM_MOUSE_BUTTON_MIDDLE    GLFW_MOUSE_BUTTON_3

#endif

#ifdef USE_VULCAN

#endif

#ifdef USE_DIRECTX

#endif