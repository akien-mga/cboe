/*
 *  consts.h
 *  BoE
 *
 *  Created by Celtic Minstrel on 13/04/09.
 *
 */

#ifndef _CONSTS_H
#define _CONSTS_H

/*
 This file contain numerous constans in form of #defines.
 Almost all of these constants cannot be changed because
 that would make the game work improperly.
 */

#define NUM_OF_PCS			6
#define INVALID_PC			NUM_OF_PCS
#define INVALID_TOWN		200

#define NUM_OF_BOATS		30
#define NUM_OF_HORSES		30

#define SFX_SMALL_BLOOD		1
#define SFX_MEDIUM_BLOOD	2
#define SFX_LARGE_BLOOD		4
#define SFX_SMALL_SLIME		8
#define SFX_BIG_SLIME		16
#define SFX_ASH				32
#define SFX_BONES			64
#define SFX_RUBBLE			128

/* stuff done flags */
#define SDF_IS_PARTY_SPLIT		304][0
#define SDF_PARTY_SPLIT_X		304][1
#define SDF_PARTY_SPLIT_Y		304][2
#define SDF_PARTY_SPLIT_PC		304][3
#define SDF_PARTY_SPLIT_TOWN	304][4 // for future use, hopefully
//#define SDF_	304][9
#define SDF_PARTY_STEALTHY		305][0
#define SDF_PARTY_FLIGHT		305][1
#define SDF_PARTY_DETECT_LIFE	305][2
#define SDF_PARTY_FIREWALK		305][3
#define SDF_SKIP_STARTUP		305][4 // preferably deprecated
#define SDF_LESS_SOUND			305][5
#define SDF_NO_TARGET_LINE		305][6
#define SDF_RESURRECT_NO_BALM	305][8
#define SDF_HOSTILES_PRESENT	305][9
#define SDF_NO_MAPS				306][0
#define SDF_NO_SOUNDS			306][1
#define SDF_NO_FRILLS			306][2
#define SDF_ROOM_DESCS_AGAIN	306][3
#define SDF_NO_INSTANT_HELP		306][4 // boolean
#define SDF_NO_SHORE_FRILLS		306][5
#define SDF_GAME_SPEED			306][6
#define SDF_EASY_MODE			306][7
#define SDF_LESS_WANDER_ENC		306][8
#define SDF_NO_TER_ANIM			306][9
/*
 [305]
 [4] will be Skip startup screen
 [6] is No targeting line (use if getting crashes)
 [5] is Fewer sounds (use if getting crashes)
 */

/* overall mode; some seem to be missing */
enum eGameMode {
	MODE_OUTDOORS = 0,
	MODE_TOWN = 1,
	MODE_TALK_TOWN = 2, // looking for someone to talk
	MODE_TOWN_TARGET = 3, // spell target, that is
	MODE_USE_TOWN = 4,
	MODE_DROP_TOWN = 5,
	MODE_COMBAT = 10,
	MODE_SPELL_TARGET = 11,
	MODE_FIRING = 12, // firing from bow or crossbow
	MODE_THROWING = 13, // throwing missle
	MODE_FANCY_TARGET = 14, // spell target, that is; I think it's for multitarget spells
	MODE_DROP_COMBAT = 15,
	MODE_TALKING = 20,
	MODE_SHOPPING = 21,
	MODE_LOOK_OUTDOORS = 35, // looking at something
	MODE_LOOK_TOWN = 36,
	MODE_LOOK_COMBAT = 37,
	MODE_STARTUP = 45,
	MODE_RESTING = 50,
};

///* adven[i].main_status */ //complete
//#define MAIN_STATUS_ABSENT	0 // absent, empty slot
//#define MAIN_STATUS_ALIVE	1
//#define MAIN_STATUS_DEAD	2
//#define MAIN_STATUS_DUST	3
//#define MAIN_STATUS_STONE	4
//#define MAIN_STATUS_FLED	5
//#define MAIN_STATUS_SURFACE	6 // fled to surface?
//#define MAIN_STATUS_WON		7
///* main status modifiers */
//#define MAIN_STATUS_SPLIT	10 // split from party


/* adven[i].skills */ //complete
#define SKILL_STRENGTH			0
#define SKILL_DEXTERITY			1
#define SKILL_INTELLIGENCE		2
#define SKILL_EDGED_WEAPONS		3
#define SKILL_BASHING_WEAPONS	4
#define SKILL_POLE_WEAPONS		5
#define SKILL_THROWN_MISSILES	6
#define SKILL_ARCHERY			7
#define SKILL_DEFENSE			8
#define SKILL_MAGE_SPELLS		9
#define SKILL_PRIEST_SPELLS		10
#define SKILL_MAGE_LORE			11
#define SKILL_ALCHEMY			12
#define SKILL_ITEM_LORE			13
#define SKILL_DISARM_TRAPS		14
#define SKILL_LOCKPICKING		15
#define SKILL_ASSASSINATION		16
#define SKILL_POISON			17
#define SKILL_LUCK				18


/* adven[i].traits */ //complete
#define TRAIT_TOUGHNESS			0
#define TRAIT_MAGICALLY_APT		1
#define TRAIT_AMBIDEXTROUS		2
#define TRAIT_NIMBLE			3
#define TRAIT_CAVE_LORE			4
#define TRAIT_WOODSMAN			5
#define TRAIT_GOOD_CONST		6
#define TRAIT_HIGHLY_ALERT		7
#define TRAIT_STRENGTH			8
#define TRAIT_RECUPERATION		9
#define TRAIT_SLUGGISH			10
#define TRAIT_MAGICALLY_INEPT	11
#define TRAIT_FRAIL				12
#define TRAIT_CHRONIC_DISEASE	13
#define TRAIT_BAD_BACK			14

/* adven[i].race */ //complete
#define RACE_HUMAN			0
#define RACE_NEPHIL			1
#define RACE_SLITH			2

/* adven[i].status*/ //complete - assign a positive value for a help pc effect, a negative for harm pc
#define STATUS_POISONED_WEAPON	0
#define STATUS_BLESS			1
#define STATUS_POISON			2
#define STATUS_HASTE			3
#define STATUS_INVULNERABLE		4
#define STATUS_MAGIC_RESISTANCE	5
#define STATUS_WEBS				6
#define STATUS_DISEASE			7
#define STATUS_INVISIBLE		8 //sanctuary
#define STATUS_DUMB				9
#define STATUS_MARTYRS_SHIELD	10
#define STATUS_ASLEEP			11
#define STATUS_PARALYZED		12
#define STATUS_ACID				13

/* damage type*/
/* used as parameter to some functions */
enum eDamageType {
	DAMAGE_WEAPON = 0,
	DAMAGE_FIRE = 1,
	DAMAGE_POISON = 2,
	DAMAGE_MAGIC = 3,
	DAMAGE_UNBLOCKABLE = 4, //from the source files - the display is the same as the magic one (damage_monst in SPECIALS.cpp)
	DAMAGE_COLD = 5,
	DAMAGE_UNDEAD = 6, //from the source files - the display is the same as the weapon one
	DAMAGE_DEMON = 7, //from the source files - the display is the same as the weapon one
// 8 and 9 aren't defined : doesn't print any damage. According to the source files the 9 is DAMAGE_MARKED though. Wrong ?
	DAMAGE_MARKED = 10, // usage: DAMAGE_MARKED + damage_type
	DAMAGE_WEAPON_MARKED = 10,
	DAMAGE_FIRE_MARKED = 11,
	DAMAGE_POISON_MARKED = 12,
	DAMAGE_MAGIC_MARKED = 13,
	DAMAGE_UNBLOCKABLE_MARKED = 14,
	DAMAGE_COLD_MARKED = 15,
	DAMAGE_UNDEAD_MARKED = 16,
	DAMAGE_DEMON_MARKED = 17,
	DAMAGE_NO_PRINT = 30, // usage: DAMAGE_NO_PRINT + damage_type
	DAMAGE_WEAPON_NO_PRINT = 30,
	DAMAGE_FIRE_NO_PRINT = 31,
	DAMAGE_POISON_NO_PRINT = 32,
	DAMAGE_MAGIC_NO_PRINT = 33,
	DAMAGE_UNBLOCKABLE_NO_PRINT = 34,
	DAMAGE_COLD_NO_PRINT = 35,
	DAMAGE_UNDEAD_NO_PRINT = 36,
	DAMAGE_DEMON_NO_PRINT = 37,
	// What about both NO_PRINT and MARKED?
};

inline void operator -= (eDamageType& cur, eDamageType othr){
	if((othr == DAMAGE_MARKED && cur >= DAMAGE_MARKED && cur < DAMAGE_NO_PRINT) ||
	   (othr == DAMAGE_NO_PRINT && cur >= DAMAGE_NO_PRINT))
		cur = (eDamageType) ((int)cur - (int)othr);
}

inline void operator += (eDamageType& cur, eDamageType othr){
	if((othr == DAMAGE_MARKED || othr == DAMAGE_NO_PRINT) && cur < DAMAGE_MARKED)
		cur = (eDamageType) ((int)cur + (int)othr);
}
//inline eDamageType operator + (eDamageType lhs, eDamageType rhs){
//	if(lhs == DAMAGE_MARKED || lhs == DAMAGE_NO_PRINT){
//		if(rhs != DAMAGE_MARKED && rhs != DAMAGE_NO_PRINT)
//			return (eDamageType) ((int)lhs + (int)rhs);
//	}else if(rhs == DAMAGE_MARKED || rhs == DAMAGE_NO_PRINT)
//		return (eDamageType) ((int)lhs + (int)rhs);
//	else{
//		int a = lhs, b = rhs, c = 0;
//		if(a > 30){
//			c += 30;
//			a -= 30;
//			if(b > 30) b -= 30;
//			else if(b > 10) b -= 10;
//			if(a == b) c += a;
//			else c += 4;
//		}else if(b > 30){
//			c += 30;
//			b -= 30;
//			if(a > 30) a -= 30;
//			else if(a > 10) a -= 10;
//			if(a == b) c += a;
//			else c += 4;
//		}else if(a > 10){
//			c += 10;
//			a -= 10;
//			if(b > 30){
//				b -= 30;
//				c += 20;
//			}else if(b > 10) b -= 10;
//			if(a == b) c += a;
//			else c += 4;
//		}else if(b > 10){
//			c += 10;
//			b -= 10;
//			if(a > 30){
//				a -= 30;
//				c += 20;
//			}else if(a > 10) a -= 10;
//			if(a == b) c += a;
//			else c += 4;
//		}
//		return (eDamageType) c; // this SHOULD guarantee a valid result...
//	}
//}

/* trap type */
/* used in pc_record_type::runTrap(...) */
enum eTrapType {
	TRAP_RANDOM = 0,
	TRAP_BLADE = 1,
	TRAP_DART = 2,
	TRAP_GAS = 3, // poisons all
	TRAP_EXPLOSION = 4, // damages all => uses c_town.difficulty rather than trap_level to calculates damages (and even c_town.difficulty /13).
	TRAP_SLEEP_RAY = 5,
	TRAP_false_ALARM = 6,
	TRAP_DRAIN_XP = 7,
	TRAP_ALERT = 8, // makes town hostile
	TRAP_FLAMES = 9, // damages all => uses trap_level (*5) to calculates damages.
	TRAP_DUMBFOUND = 10, //dumbfound all
	TRAP_DISEASE = 11,
	TRAP_DISEASE_ALL = 12,
};

/*      items[i].type    a.k.a type of weapon         */
#define ITEM_EDGED			1
#define ITEM_BASHING		2
#define ITEM_POLE			3

/*      items[i].variety    a.k.a item type (in editor)      */
#define ITEM_TYPE_NO_ITEM			0
#define ITEM_TYPE_ONE_HANDED		1
#define ITEM_TYPE_TWO_HANDED		2
#define ITEM_TYPE_GOLD				3
#define ITEM_TYPE_BOW				4
#define ITEM_TYPE_ARROW				5
#define ITEM_TYPE_THROWN_MISSILE	6
#define ITEM_TYPE_POTION			7 // potion/magic item
#define ITEM_TYPE_SCROLL			8 // scroll/magic item
#define ITEM_TYPE_WAND				9
#define ITEM_TYPE_TOOL				10
#define ITEM_TYPE_FOOD				11
#define ITEM_TYPE_SHIELD			12
#define ITEM_TYPE_ARMOR				13
#define ITEM_TYPE_HELM				14
#define ITEM_TYPE_GLOVES			15
#define ITEM_TYPE_SHIELD_2			16
/* don't know why a second type of shield is used ; it is actually checked
 * in the armor code (item >= 12 and <= 17)
 * and you can't equip another (12) shield while wearing it ... I didn't
 * find a single item with this property in the bladbase.exs ... */
#define ITEM_TYPE_BOOTS				17
#define ITEM_TYPE_RING				18
#define ITEM_TYPE_NECKLACE			19
#define ITEM_TYPE_WEAPON_POISON		20
#define ITEM_TYPE_NON_USE_OBJECT	21
#define ITEM_TYPE_PANTS				22
#define ITEM_TYPE_CROSSBOW			23
#define ITEM_TYPE_BOLTS				24
#define ITEM_TYPE_MISSILE_NO_AMMO	25 //e.g slings

/*      items[i].ability      */

/* Weapons Ability */
#define ITEM_NO_ABILITY				0        
#define ITEM_FLAMING_WEAPON			1
#define ITEM_DEMON_SLAYER			2
#define ITEM_UNDEAD_SLAYER			3
#define ITEM_LIZARD_SLAYER			4
#define ITEM_GIANT_SLAYER			5
#define ITEM_MAGE_SLAYER			6
#define ITEM_PRIEST_SLAYER			7
#define ITEM_BUG_SLAYER				8
#define ITEM_ACIDIC_WEAPON			9
#define ITEM_SOULSUCKER				10
#define ITEM_DRAIN_MISSILES			11
#define ITEM_WEAK_WEAPON			12
#define ITEM_CAUSES_FEAR			13
#define ITEM_POISONED_WEAPON		14

/* General Ability */
#define ITEM_PROTECTION				30
#define ITEM_FULL_PROTECTION		31
#define ITEM_FIRE_PROTECTION		32
#define ITEM_COLD_PROTECTION		33
#define ITEM_POISON_PROTECTION		34
#define ITEM_MAGIC_PROTECTION		35
#define ITEM_ACID_PROTECTION		36
#define ITEM_SKILL					37
#define ITEM_STRENGTH				38
#define ITEM_DEXTERITY				39
#define ITEM_INTELLIGENCE			40
#define ITEM_ACCURACY				41
#define ITEM_THIEVING				42
#define ITEM_GIANT_STRENGTH			43
#define ITEM_LIGHTER_OBJECT			44
#define ITEM_HEAVIER_OBJECT			45
#define ITEM_OCCASIONAL_BLESS		46
#define ITEM_OCCASIONAL_HASTE		47
#define ITEM_LIFE_SAVING			48
#define ITEM_PROTECT_FROM_PETRIFY	49
#define ITEM_REGENERATE				50
#define ITEM_POISON_AUGMENT			51
#define ITEM_DISEASE_PARTY			52
#define ITEM_WILL					53
#define ITEM_FREE_ACTION			54
#define ITEM_SPEED					55
#define ITEM_SLOW_WEARER			56
#define ITEM_PROTECT_FROM_UNDEAD	57
#define ITEM_PROTECT_FROM_DEMONS	58
#define ITEM_PROTECT_FROM_HUMANOIDS	59
#define ITEM_PROTECT_FROM_REPTILES	60
#define ITEM_PROTECT_FROM_GIANTS	61
#define ITEM_PROTECT_FROM_DISEASE	62

/* NonSpell Use ;  the constant refers to both the positive and negative effect (don't mind the name). */
#define ITEM_POISON_WEAPON			70 //put poison on weapon
#define ITEM_BLESS_CURSE			71
#define ITEM_AFFECT_POISON			72
#define ITEM_HASTE_SLOW				73
#define ITEM_AFFECT_INVULN			74
#define ITEM_AFFECT_MAGIC_RES		75
#define ITEM_AFFECT_WEB				76
#define ITEM_AFFECT_DISEASE			77
#define ITEM_AFFECT_SANCTUARY		78
#define ITEM_AFFECT_DUMBFOUND		79
#define ITEM_AFFECT_MARTYRS_SHIELD	80
#define ITEM_AFFECT_SLEEP			81
#define ITEM_AFFECT_PARALYSIS		82
#define ITEM_AFFECT_ACID			83
#define ITEM_BLISS					84
#define ITEM_AFFECT_EXPERIENCE		85
#define ITEM_AFFECT_SKILL_POINTS	86
#define ITEM_AFFECT_HEALTH			87
#define ITEM_AFFECT_SPELL_POINTS	88
#define ITEM_DOOM					89
#define ITEM_LIGHT					90
#define ITEM_STEALTH				91
#define ITEM_FIREWALK				92
#define ITEM_FLYING					93
#define ITEM_MAJOR_HEALING			94

/* Spell Usable */

#define ITEM_SPELL_FLAME				110
#define ITEM_SPELL_FIREBALL				111
#define ITEM_SPELL_FIRESTORM			112
#define ITEM_SPELL_KILL					113
#define ITEM_SPELL_ICE_BOLT				114
#define ITEM_SPELL_SLOW					115
#define ITEM_SPELL_SHOCKWAVE			116
#define ITEM_SPELL_DISPEL_UNDEAD		117
#define ITEM_SPELL_DISPEL_SPIRIT		118
#define ITEM_SPELL_SUMMONING			119
#define ITEM_SPELL_MASS_SUMMONING		120
#define ITEM_SPELL_ACID_SPRAY			121
#define ITEM_SPELL_STINKING_CLOUD		122
#define ITEM_SPELL_SLEEP_FIELD			123
#define ITEM_SPELL_VENOM				124
#define ITEM_SPELL_SHOCKSTORM			125
#define ITEM_SPELL_PARALYSIS			126
#define ITEM_SPELL_WEB_SPELL			127
#define ITEM_SPELL_STRENGTHEN_TARGET	128 //wand of carrunos effect
#define ITEM_SPELL_QUICKFIRE			129
#define ITEM_SPELL_MASS_CHARM			130
#define ITEM_SPELL_MAGIC_MAP			131
#define ITEM_SPELL_DISPEL_BARRIER		132
#define ITEM_SPELL_MAKE_ICE_WALL		133
#define ITEM_SPELL_CHARM_SPELL			134
#define ITEM_SPELL_ANTIMAGIC_CLOUD		135

/* Reagents */
#define ITEM_HOLLY				150 // Holly/Toadstool
#define ITEM_COMFREY_ROOT		151
#define ITEM_GLOWING_NETTLE		152
#define ITEM_CRYPT_SHROOM		153 // Crypt Shroom/Wormgr.
#define ITEM_ASPTONGUE_MOLD		154
#define ITEM_EMBER_FLOWERS		155
#define ITEM_GRAYMOLD			156
#define ITEM_MANDRAKE			157
#define ITEM_SAPPHIRE			158
#define ITEM_SMOKY_CRYSTAL		159
#define ITEM_RESSURECTION_BALM	160
#define ITEM_LOCKPICKS			161

/* Missiles */

#define ITEM_MISSILE_RETURNING		170
#define ITEM_MISSILE_LIGHTNING		171
#define ITEM_MISSILE_EXPLODING		172
#define ITEM_MISSILE_ACID			173
#define ITEM_MISSILE_SLAY_UNDEAD	174
#define ITEM_MISSILE_SLAY_DEMON		175
#define ITEM_MISSILE_HEAL_TARGET	176

/* Terrains Specials Properties : scenario.ter_types[i].special */      //complete

#define TER_SPEC_NONE 0
#define TER_SPEC_CHANGE_WHEN_STEP_ON 1
#define TER_SPEC_DOES_FIRE_DAMAGE 2
#define TER_SPEC_DOES_COLD_DAMAGE 3
#define TER_SPEC_DOES_MAGIC_DAMAGE 4
#define TER_SPEC_POISON_LAND 5
#define TER_SPEC_DISEASED_LAND 6
#define TER_SPEC_CRUMBLING_TERRAIN 7
#define TER_SPEC_LOCKABLE_TERRAIN 8
#define TER_SPEC_UNLOCKABLE_TERRAIN 9
#define TER_SPEC_UNLOCKABLE_BASHABLE 10
#define TER_SPEC_IS_A_SIGN 11
#define TER_SPEC_CALL_LOCAL_SPECIAL 12
#define TER_SPEC_CALL_SCENARIO_SPECIAL 13
#define TER_SPEC_IS_A_CONTAINER 14
#define TER_SPEC_WATERFALL 15
#define TER_SPEC_CONVEYOR_NORTH 16
#define TER_SPEC_CONVEYOR_EAST 17
#define TER_SPEC_CONVEYOR_SOUTH 18
#define TER_SPEC_CONVEYOR_WEST 19
#define TER_SPEC_BLOCKED_TO_MONSTERS 20
#define TER_SPEC_TOWN_ENTRANCE 21
#define TER_SPEC_CAN_BE_USED 22
#define TER_SPEC_CALL_SPECIAL_WHEN_USED 23

//stuff used in blxactions.c

//Startup button rects (also used in startup.c)
#define STARTBTN_LOAD		0
#define STARTBTN_NEW		1
#define STARTBTN_ORDER		2
#define STARTBTN_JOIN		3
#define STARTBTN_CUSTOM		4

//Shop rects
#define SHOPRECT_WHOLE_AREA		0
#define SHOPRECT_ACTIVE_AREA	1
#define SHOPRECT_GRAPHIC		2
#define SHOPRECT_ITEM_NAME		3
#define SHOPRECT_ITEM_COST		4
#define SHOPRECT_ITEM_EXTRA		5
#define SHOPRECT_ITEM_HELP		6

// Item button rects
#define ITEMBTN_NAME		0
#define ITEMBTN_USE			1
#define ITEMBTN_GIVE		2
#define ITEMBTN_DROP		3
#define ITEMBTN_INFO		4
#define ITEMBTN_SPEC		5 // Sell, Identify, or Enchant

// PC button rects
#define PCBTN_NAME			0
#define PCBTN_HP			1
#define PCBTN_SP			2
#define PCBTN_INFO			3
#define PCBTN_TRADE			4

//Spell select
#define SPELL_SELECT_NONE		0
#define SPELL_SELECT_ACTIVE		1
#define SPELL_SELECT_ANY		2

//Spell refer
#define SPELL_REFER				0
#define SPELL_IMMED				1
#define SPELL_TARGET			2
#define SPELL_FANCY_TARGET		3

#endif