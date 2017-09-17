CXX = g++-5
CXXFLAGS = -std=c++14 -Wall -MMD
EXEC = cc3k
OBJECTS = main.o TextDisplay.o ChamberCrawler.o Floor.o Factory.o Character.o Player.o Enemy.o Shade.o Drow.o Vampire.o Troll.o Goblin.o Jeff.o Human.o Dwarf.o Elf.o Orcs.o Merchant.o Dragon.o Halfing.o Potion.o RH.o BA.o BD.o PH.o WA.o WD.o Treasure.o SmallTreasure.o NormalTreasure.o MerchHoard.o DragonHoard.o Floor1.o Floor2.o Floor3.o Floor4.o Floor5.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
