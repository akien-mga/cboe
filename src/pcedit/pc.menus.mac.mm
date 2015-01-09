//
//  pc.menus.mac.mm
//  BoE
//
//  Created by Celtic Minstrel on 14-04-15.
//
//

#include "pc.menus.h"
#include <Cocoa/Cocoa.h>
#include "item.h"
#include "universe.h"

#ifndef __APPLE__
#error pc.menus.mm is Mac-specific code; try compiling pc.menus.win.cpp instead
#endif

using MenuHandle = NSMenu*;

extern cUniverse univ;
extern fs::path file_in_mem;
extern bool scen_items_loaded;
MenuHandle menu_bar_handle;
MenuHandle apple_menu, file_menu, reg_menu, extra_menu, items_menu[4];

@interface MenuHandler : NSObject
-(void) itemMenu:(id) sender;
-(void) menuChoice:(id) sender;
@end

@interface ItemWrapper : NSObject
+(id) withItem:(int) theItem;
-(cItemRec&) item;
-(void) setItem:(int) theItem;
@end

static void setMenuCallback(NSMenuItem* item, id targ, SEL selector, int num) {
	[item setTarget: targ];
	[item setAction: selector];
	[item setRepresentedObject: [[NSNumber numberWithInt: num] retain]];
}

void init_menubar() {
	static bool inited = false;
	if(inited) return;
	inited = true;
	
	NSApplication* app = [NSApplication sharedApplication];
	[NSBundle loadNibNamed: @"pc.menu" owner: app];
	menu_bar_handle = [app mainMenu];
	
	apple_menu = [[menu_bar_handle itemWithTitle: @"BoE Character Editor"] submenu];
	file_menu = [[menu_bar_handle itemWithTitle: @"File"] submenu];
	reg_menu = [[menu_bar_handle itemWithTitle: @"Edit Party"] submenu];
	extra_menu = [[menu_bar_handle itemWithTitle: @"Scenario Edit"] submenu];
	items_menu[0] = [[menu_bar_handle itemWithTitle: @"Items 1"] submenu];
	items_menu[1] = [[menu_bar_handle itemWithTitle: @"Items 2"] submenu];
	items_menu[2] = [[menu_bar_handle itemWithTitle: @"Items 3"] submenu];
	items_menu[3] = [[menu_bar_handle itemWithTitle: @"Items 4"] submenu];
	
	static const eMenu file_choices[] = {
		eMenu::FILE_OPEN, eMenu::FILE_CLOSE, eMenu::NONE, eMenu::FILE_SAVE, eMenu::FILE_SAVE_AS, eMenu::FILE_REVERT,
	};
	static const eMenu party_choices[] = {
		eMenu::EDIT_GOLD, eMenu::EDIT_FOOD, eMenu::EDIT_ALCHEMY, eMenu::NONE,
		eMenu::HEAL_DAMAGE, eMenu::RESTORE_MANA, eMenu::RAISE_DEAD, eMenu::CURE_CONDITIONS, eMenu::NONE,
		eMenu::EDIT_MAGE, eMenu::EDIT_PRIEST, eMenu::EDIT_TRAITS, eMenu::EDIT_SKILLS, eMenu::EDIT_XP, eMenu::NONE,
		eMenu::REUNITE_PARTY, eMenu::OWN_VEHICLES,
	};
	static const eMenu scen_choices[] = {
		eMenu::EDIT_DAY, eMenu::NONE, eMenu::LEAVE_TOWN, eMenu::RESET_TOWNS, eMenu::ADD_OUT_MAPS, eMenu::ADD_TOWN_MAPS,
		eMenu::NONE, eMenu::LEAVE_SCENARIO, eMenu::SET_SDF,
	};
	
	MenuHandler* handler = [[[MenuHandler alloc] init] retain];
	setMenuCallback([apple_menu itemWithTitle: @"About BoE Character Editor"], handler, @selector(menuChoice:), int(eMenu::ABOUT));
	setMenuCallback([apple_menu itemWithTitle: @"Quit BoE Character Editor"], handler, @selector(menuChoice:), int(eMenu::QUIT));
	
	int i = 0;
	for(eMenu opt : file_choices)
		setMenuCallback([file_menu itemAtIndex: i++], handler, @selector(menuChoice:), int(opt));
	i = 0;
	for(eMenu opt : party_choices)
		setMenuCallback([reg_menu itemAtIndex: i++], handler, @selector(menuChoice:), int(opt));
	i = 0;
	for(eMenu opt : scen_choices)
		setMenuCallback([extra_menu itemAtIndex: i++], handler, @selector(menuChoice:), int(opt));
	
	update_item_menu();
	menu_activate();
}

void menu_activate() {
	if(file_in_mem.empty()) {
		for(int i = 3; i < [file_menu numberOfItems]; i++)
			[[file_menu itemAtIndex: i] setEnabled: NO];
		[[menu_bar_handle itemWithTitle: @"Edit Party"] setEnabled: NO];
		[[menu_bar_handle itemWithTitle: @"Scenario Edit"] setEnabled: NO];
	} else {
		for(int i = 3; i < [file_menu numberOfItems]; i++)
			[[file_menu itemAtIndex: i] setEnabled: YES];
		[[menu_bar_handle itemWithTitle: @"Edit Party"] setEnabled: YES];
		[[menu_bar_handle itemWithTitle: @"Scenario Edit"] setEnabled: YES];
	}
}

void update_item_menu() {
	id targ = [[file_menu itemAtIndex: 0] target];
	cItemRec(& item_list)[400] = univ.scenario.scen_items;
	for(int j = 0; j < 4; j++){
		[items_menu[j] removeAllItems];
		if(!scen_items_loaded) {
			[[items_menu[j] addItemWithTitle: @"Items Not Loaded" action: @selector(itemMenu:) keyEquivalent: @""] setEnabled: NO];
		} else for(int i = 0; i < 100; i++) {
			ItemWrapper* item = [ItemWrapper withItem: i + 100 * j];
			NSString* item_name = [NSString stringWithCString: item_list[i + j * 100].full_name.c_str() encoding: NSASCIIStringEncoding];
			NSMenuItem* choice = [items_menu[j] addItemWithTitle: item_name action: @selector(itemMenu:) keyEquivalent: @""];
			[choice setTarget: targ];
			// TODO: Also disable gold or food
			[choice setEnabled: [item item].variety != eItemType::NO_ITEM];
			[choice setRepresentedObject: item];
		}
	}
}

@implementation MenuHandler
-(void) itemMenu:(id) sender {
	ItemWrapper* item = [sender representedObject];
	cItemRec& theItem = [item item];
	(void) theItem; // Suppress "unused parameter" warning
	for(int i = 0; i < 4; i++) {
		int whichItem = [items_menu[i] indexOfItem: sender];
		if(whichItem >= 0)
			handle_item_menu(whichItem + 100 * i);
	}
}

-(void) menuChoice:(id) sender {
	eMenu opt = eMenu([[sender representedObject] intValue]);
	handle_menu_choice(opt);
}
@end

@implementation ItemWrapper {
	int itemID;
}

+(id) withItem:(int) theItem {
	ItemWrapper* item = [[ItemWrapper alloc] init];
	[item setItem: theItem];
	return item;
}

-(void) setItem:(int) theItem {
	self->itemID = theItem;
}

-(cItemRec&) item {
	return univ.scenario.scen_items[self->itemID];
}

@end