//***********************************************************
//
//  AnimalHouseMain.cpp
//
//  An adventure game based on the movie Animal House and
//  other Greek life stereotypes.
//
//  Author: Nate McCain
//
//  This program is entirely my own work.
//
//  Created by Nate McCain on 6/12/14.
//  Copyright (c) 2014 Nate McCain. All rights reserved.
//***********************************************************
// It is recommended to play this game with the output screen
// set to full-screen.
//***********************************************************

#include <iostream>
#include <string>

using namespace std;

/* Lists the void functions that describe all of the rooms. */
 
// Rooms from Row A.
void DescribeRoomA1();
void DescribeRoomA2();
void DescribeRoomA3();
void DescribeRoomA4();
void DescribeRoomA5();
// Rooms from Row B.
void DescribeRoomB1();
void DescribeRoomB2();
void DescribeRoomB3();
void DescribeRoomB4();
void DescribeRoomB5();
// Rooms from Row C.
void DescribeRoomC1();
void DescribeRoomC2();
void DescribeRoomC3();
void DescribeRoomC4();
void DescribeRoomC5();
// Rooms from Row D.
void DescribeRoomD1();
void DescribeRoomD2();
void DescribeRoomD3();
void DescribeRoomD4();
void DescribeRoomD5();
// Rooms from Row E.

void DescribeRoomE1();  // Starting room.
void DescribeRoomE2();
void DescribeRoomE3();
void DescribeRoomE4();
void DescribeRoomE5();


const string INDENT = "        ";

//***********************************************************************

// Define doors (Nibble 0)

#define DOOR_NORTH                      0x00000001  // decimal value is 1.
#define DOOR_EAST                       0x00000002  // decimal value is 2.
#define DOOR_SOUTH                      0x00000004  // decimal value is 4.
#define DOOR_WEST                       0x00000008  // decimal value is 8.

// Define treasure items (Nibble 1)

#define OMEGA_THETA_PI_RITUAL_BOOK      0x00000010  // decimal value is 16.
#define PLEDGE_MASTER_CHIP              0x00000020  // decimal value is 32.
#define THE_GOAT                        0x00000040  // decimal value is 64.
#define PLEDGE_BOOK_SIGNED              0x00000080  // decimal value is 128.

// Define creatures (Nibbles 2 and 3)

#define CAMPUS_SAFETY_OFFICER           0x00000100  // decimal value is 256.
#define OFFICER_JOHNNY_AUSTIN           0x00000200  // decimal value is 512.
#define OMEGA_THETA_PI_MEMBER           0x00000400  // decimal value is 1024.
#define ANGRY_GAMMA_SORORITY_GIRL       0x00000800  // decimal value is 2048.
#define ANTI_GREEK_LIFE_STUDENT         0x00001000  // decimal value is 4096.
#define HIPPY                           0x00002000  // decimal value is 8192.
#define DEAN_VERNON_WORMER              0x00004000  // decimal value is 16284.
#define GREGORY_MARMALARD               0x00008000  // decimal value is 32768

// Define dangerous creatures (Nibbles 4)
#define DEADLY                          0x00010000  // decimal value is 65536.
#define DANGEROUS                       0x00020000  // decimal value is 131072.
#define CAUTION                         0x00040000  // decimal value is 262144.
#define FRIENDLY                        0x00080000  // decimal value is 524288.

//***********************************************************************

void DescribeRoomContents(int roomDesc, int row, int col);
void BuildRooms(unsigned int rooms[][5]);

//***********************************************************************

// Prototype function to handle the TAKE command.
int TakeItem(unsigned int rooms[5][5], int row, int col, string Object);


int main()
{
    string cmdVerb;         // String object to hold player's command verb.
    string cmdObj;          // String object to hold player's command object.

    int iRow;               // Index of current game grid row.
    int iCol;               // Index of current game grid column.
    int iNumRows;           // Number of rows in the game grid.
    int iNumCols;           // Number of columns in the game grid.
    
    iRow = 4;               // Player starts in E1.
    iCol = 0;
    iNumRows = 4;
    iNumCols = 4;
    
// Player possessions variables.
    int iPlayer = 0;        // Use bits to flag what the player is carrying.
    int endRow = 3;          // Row of destination when all items have been found.
    int endCol = 0;          // Column of destination when all items have been found.
    
    unsigned int Faber[5][5];   // 2-D array of ints to define the room contents, etc.
// Make sure the array is initially all zeros.
    for(int row = 0; row < 5; row++)
        for(int col = 0; col < 5; col++)
            Faber[row][col] = 0;
    
// Add a call to Build Rooms function.
    BuildRooms(Faber);  // Builds the rooms.
    
    
// Printing the game instructions because you have to start somewhere.

// Opening Greeting/Header.
    cout << INDENT << INDENT << INDENT << " You Have Received A Bid To Join " << endl
         << INDENT << INDENT << INDENT << "    Delta Tau Chi Fraternity " << endl
         << INDENT << INDENT << INDENT << "       At Faber College. " << endl << endl << endl;
    
// Introduction to the scenario.
    cout << INDENT << "Congratulations freshman. You have received a bid to join our sacred " << endl
         << "fraternity. My name is Eric Stratton, and I will guide you to initiation. Be " << endl
         << "warned, earning initiation will not be simple. You must complete several tasks " << endl
         << "during the 8-week pledge period. At the end of the 8 weeks, you must submit to " << endl
         << "me the four items necessary to be initiated. I will only reveal an item at the " << endl
         << "beginning of the week in which they must be found. To obtain the items necessary" << endl
         << "for initiation, you must complete minor tasks for the initiated brothers of our " << endl
         << "fraternity. Whenever you obtain an item, you must return it to the Delta House. " << endl
         << "Here is your pledge book. Study it, and return to me for your first task. " << endl
         << endl << endl;
    
// Instructions for the player.
    
    cout << INDENT << INDENT << INDENT << " Instructions for the Pledge " << endl << endl;
    
    cout << INDENT << " To move between rooms, use the “GO” command followed by a direction " << endl
         << "(NORTH, EAST, SOUTH, or WEST). When an item is found, pick it up with the " << endl
         << "“TAKE” command followed by the item’s name. To give an item, use the “GIVE” " << endl
         << "command followed by the item’s name. Once an item is returned to the person " << endl
         << "requesting it, the pledge can return to the Freshman Dorm and use the “SLEEP " << endl
         << "BED” command to advance to the next week of pledging. Be warned though, the " << endl
         << "Delta’s did not achieve their status as the best fraternity on campus without " << endl
         << "making a few enemies. You must flee from encounters with these as they could " << endl
         << "get you expelled, or even worse, dropped." << endl << endl;
    
    cout << INDENT << INDENT << INDENT << "       Get to work, Pledge!" << endl << endl << endl;
    
//********************************
// User's command.
//********************************
    
// Wait for player to read instructions and then press Enter key to start.
    
    cout << "Press the Enter key to begin\n" <<endl;
    getc(stdin);    // Gets a single key press.
    
// Describes the starting room.
    DescribeRoomE1();
    
//********************************************************************
// Start the game loop.
//********************************************************************
    bool bQuitGame;         // Boolean value bQuitGame.
    bQuitGame = false;      // Initialize end of game flag.
    
    while (!bQuitGame)      // While NOT bQuitGame
    {
    
// Get the player's command.
        cout << "What would you like to do? " << endl;
        cin >> cmdVerb >> cmdObj;
    
// Make sure player's commands are all caps.
        int idx;    // Index variable for command.
        int idy;    // Index variable for object.
        
        idx = 0;    // Set int index for command to 0.
        idy = 0;    // Set int index for object to 0.
        
        while (idx < cmdVerb.length())      // Command Verbs will now be uppercase!
        {
            cmdVerb[idx] = toupper(cmdVerb[idx]);
            idx++;  // Increment to next index.
        }
        
        while (idy < cmdObj.length())       // Command Objects will now be uppercase!
        {
            cmdObj[idy] = toupper(cmdObj[idy]);
            idy++;  // Increment to next index.
        }
    
    
// Parse the player's command.
// Valid Commands           Valid Objects
// GO                       NORTH, EAST, SOUTH, WEST
// TAKE                     TBD
// QUIT                     GAME
    
// Check for GO command.
    
        if (cmdVerb == "GO")
        {
            cout << "Command verb is GO." << endl;
        
// Check direction to go in.
            
// Dircetion is NORTH.
            if (cmdObj == "NORTH")
            {
// Can we move that way?
                if(Faber[iRow][iCol] & DOOR_NORTH)
                {
                    iRow--; // Move up a row.
                    DescribeRoomContents(Faber[iRow][iCol], iRow, iCol);
                    
                }
                
                cout << "Direction is NORTH." << endl;
            }
            
// Direction is EAST.
            else if (cmdObj == "EAST")
                {
// Can we move that way?
                    if (Faber[iRow][iCol] & DOOR_EAST)
                    {
                        iCol++; // Move right a column.
                        DescribeRoomContents(Faber[iRow][iCol], iRow, iCol);
                        
                    }
                    cout << "Direction is EAST." << endl;
                }
// Direction is SOUTH.
            else if (cmdObj == "SOUTH")
            {
// Can we move that way?
                if (Faber[iRow][iCol] & DOOR_SOUTH)
                {
                    iRow++; // Move down a row.
                    DescribeRoomContents(Faber[iRow][iCol], iRow, iCol);
                    
                }
                cout << "Direction is SOUTH." << endl;
            }
// Direction is WEST.
            else if (cmdObj == "WEST")
            {
// Can we move that way?
                if (Faber[iRow][iCol] & DOOR_WEST)
                {
                    iCol--; // Move left a column.
                    DescribeRoomContents(Faber[iRow][iCol], iRow, iCol);
                    
                }
                cout << "Direction is WEST." << endl;
            }
        
            else
            {
                cout << "I don't understand GO " << cmdObj << endl;
            }
// Check to see if player is in the final destination room.
            if((iRow == endRow) && (iCol == endCol))    // Are we there yet?
            {
// Check to see if the player has all the items.
                if((iPlayer & THE_GOAT) &&
                   (iPlayer & PLEDGE_MASTER_CHIP) &&
                   (iPlayer & PLEDGE_BOOK_SIGNED) &&
                   (iPlayer & OMEGA_THETA_PI_RITUAL_BOOK))
                {
                    // Yes, so tell the player they won.
                    cout << endl << endl;
                    cout << "Congratulations. You have completed pledgeship. We shall begin initiation." << endl << endl
                         << "All those who are not initiated or awaiting initiation must leave now or" << endl
                         << "face the consequences." << endl << endl;
                    
                    // Set boolean flag to end the game.
                    bQuitGame = true;
                    
                }
            }
            
    
        } // End of the if GO command.
        
        
// Handle the TAKE command.
        else if(cmdVerb == "TAKE")
        {
            int takeVal = TakeItem(Faber, iRow, iCol, cmdObj);
// If takeVal is not zero, the player successfully took the item and it was removed from the room.
            if(takeVal)
            {
                iPlayer |= takeVal; // Add this item to the player.
                cout << "You are now carrying the " << cmdObj << endl << endl;
            }
            else
                cout << "You cannot take the " << cmdObj << " from this location." << endl << endl;
        }
    
// Check for QUIT command.
    
        else if (cmdVerb == "QUIT")
        {
            bQuitGame = true;
        }
    
// Add "else-if" checks for other commands here.
        
        
// Tell player that the entered command is not understood.
        else
        {
            cout << "I don't understand " << cmdVerb << '.' << endl;
        }
// Next two lines are for testing only. Commenting out after testing.
/*
            cout << "Command is: " << cmdVerb << ' ' << cmdObj << endl;
            cout << "Location is: Row " << iRow << ", Column " << iCol << '.' << endl << endl;
*/
    }   // End game while loop.
    
    return 0;
}

//***********************************************************************
// Describe the room contents based on the int flag.
// roomDesc- int defining room contents as a series of bit flags.
// row, col- int giving current row and column of room.
//***********************************************************************

void DescribeRoomContents(int roomDesc, int row, int col)
{
// Call appropriate function to describe room.
    
    switch(row)
    {
//***********************************************************************
            
        case 0: // Handle row A.
            
            switch(col)
        {
                
            case 0: // Handle col 0.
                DescribeRoomA1();
                break;
            case 1: // Handle col 1.
                DescribeRoomA2();
                break;
            case 2: // Handle col 2.
                DescribeRoomA3();
                break;
            case 3: // Handle col 3.
                DescribeRoomA4();
                break;
            case 4: // Handle col 4.
                DescribeRoomA5();
                break;
                
        }
            break;  // Break from case row A.
            
//***********************************************************************
            
        case 1: // Handle row B.
            
            switch(col)
        {
            case 0: // Handle col 0.
                DescribeRoomB1();
                break;
            case 1: // Handle col 1.
                DescribeRoomB2();
                break;
            case 2: // Handle col 2.
                DescribeRoomB3();
                break;
            case 3: // Handle col 3.
                DescribeRoomB4();
                break;
            case 4: // Handle col 4.
                DescribeRoomB5();
                break;
        }
            break;  // Break from case row B.
            
//***********************************************************************
            
        case 2: // Handle row C.
            
            switch(col)
        {
                
            case 0: // Handle col 0.
                DescribeRoomC1();
                break;
            case 1: // Handle col 1.
                DescribeRoomC2();
                break;
            case 2: // Handle col 2.
                DescribeRoomC3();
                break;
            case 3: // Handle col 3.
                DescribeRoomC4();
                break;
            case 4: // Handle col 4.
                DescribeRoomC5();
                break;
                
        }
            break;  // Break from case row C.
            
//***********************************************************************
            
        case 3: // Handle row D.
            
            switch(col)
        {
            case 0: // Handle col 0.
                DescribeRoomD1();
                break;
            case 1: // Handle col 1.
                DescribeRoomD2();
                break;
            case 2: // Handle col 2.
                DescribeRoomD3();
                break;
            case 3: // Handle col 3.
                DescribeRoomD4();
                break;
            case 4: // Handle col 4.
                DescribeRoomD5();
                break;
        }
            break;  // Break from case row D.
            
//***********************************************************************
            
        case 4: // Handle row E.
            
            switch(col)
        {
                
            case 0: // Handle col 0.
                DescribeRoomE1();
                break;
            case 1: // Handle col 1.
                DescribeRoomE2();
                break;
            case 2: // Handle col 2.
                DescribeRoomE3();
                break;
            case 3: // Handle col 3.
                DescribeRoomE4();
                break;
            case 4: // Handle col 4.
                DescribeRoomE5();
                break;
                
        }
            break;  // Break from case row E.
            
//***********************************************************************
            
    }       // End switch on row.

    
    
// Describe creatures if any here.
    if(roomDesc & CAMPUS_SAFETY_OFFICER)
        cout << "You see a campus safety officer looking to get someone in trouble." << endl;
    
    if(roomDesc & OFFICER_JOHNNY_AUSTIN)
        cout << "You see campus safety officer Johnny Austin. He doesn't play by the rules." << endl;
    
    if(roomDesc & OMEGA_THETA_PI_MEMBER)
        cout << "You see a member of your rival fraternity, Omega Theta Pi." << endl;
    
    if(roomDesc & ANGRY_GAMMA_SORORITY_GIRL)
        cout << "You see an angry Gamma girl from Emily Dickenson College." << endl;
    
    if(roomDesc & ANTI_GREEK_LIFE_STUDENT)
        cout << "You see a student that is upset about not getting a bid. They are attempting to get signatures to ban Greek life." << endl;
    
    if(roomDesc & HIPPY)
        cout << "You see a dirty hippy. Or did you smell them first?" << endl;
    
    if(roomDesc & DEAN_VERNON_WORMER)
        cout << "You see Vernon Wormer, Dean of Faber College." << endl;
    
    if(roomDesc & GREGORY_MARMALARD)
        cout << "You see Gregory Marmalard, the self-righteous president of Omega Theta Pi fraternity." << endl;
    
    
// Tell if they are dangerous creatures.
    if(roomDesc & DEADLY)
        cout << "This person is deadly. You should probably go somewhere else." << endl;
    
    if(roomDesc & DANGEROUS)
        cout << "This person is dangerous. It would be advised to avoid confrontation." << endl;
    
    if(roomDesc & CAUTION)
        cout << "This person could be dangerous. Would you like to find out?" << endl;
    
    if(roomDesc & FRIENDLY)
        cout << "This person is harmless. Do as you please." << endl;
    
    
// Check for treasure items.
    if(roomDesc & OMEGA_THETA_PI_RITUAL_BOOK)
        cout << "You see Omega Theta Pi's ritual BOOK." << endl;
        
    if(roomDesc & PLEDGE_MASTER_CHIP)
        cout << "You see the Pledge Master's CHIP." << endl;
        
    if(roomDesc &THE_GOAT)
        cout << "You see the sacred GOAT of all rituals." << endl;
        
    if(roomDesc & PLEDGE_BOOK_SIGNED)
        cout << "You see your pledge BOOK with all of your brothers' signatures inside." << endl;
        
    
// Check the doors.
   if(roomDesc & DOOR_NORTH)
       cout << "There is a door to the North." << endl;
       
   if(roomDesc & DOOR_EAST)
       cout << "There is a door to the East." << endl;
       
   if(roomDesc & DOOR_SOUTH)
       cout << "There is a door to the South." << endl;
       
   if(roomDesc & DOOR_WEST)
       cout << "There is a door to the West." << endl;
       
    
}   // End of void function.



//***********************************************************************


// Room A-1.
void DescribeRoomA1()
{
    cout << "You are in the Freshman Dorm.                                               " << endl
    << "Your room has white cinder-blocks for walls and a short flaky white ceiling." << endl
    << "You see two generic cheap beds, desks, dressers, and office chairs for you  " << endl
    << "and your roommate. The room is empty... Do you even have a roommate or did  " << endl
    << "you run him off?                                                            " << endl;
}

// Room A-2.
void DescribeRoomA2()
{
    cout << "You are standing on North University Street.                " << endl
    << "The surrounding environment is modeled after Oxford. You can see students     " << endl
    << "strolling along the sidewalks peacefully, and others sprinting to their next  " << endl
    << "class. The shade blocks the Sun just enough to enjoy it without becoming too  " << endl
    << "hot. Though this is technically a street, the only drivers on it are commuting" << endl
    << "students and school employees.                                                " << endl;
}

// Room A-3.
void DescribeRoomA3()
{
    cout << "You are standing at the Faber College Entrance.                               " << endl
    << "There is a black gate surrounding the college, except at this entrance. There " << endl
    << "is an Oxford-styled sign that has \"Faber College\" inscribed on it. The area " << endl
    << "is covered in a peaceful, Summer shade. It is obvious the college spent a lot " << endl
    << "of money in its appearance. Only the good parts of the busy campus are visible" << endl
    << "from here...                                                                  " << endl;
}

// Room A-4.
void DescribeRoomA4()
{
    cout << "You are pulled over on the Interstate." << endl
    << "It is dark outside, but the skies are clear allowing for the stars and full   " << endl
    << "moon to be visible. There are tall, eery trees on either side of the road. The" << endl
    << "smooth road is empty, but something in the air is preventing the environment  " << endl
    << "from seeming peaceful..." << endl;
}


// Room A-5.
void DescribeRoomA5()
{
    cout << "You are standing in front of the Gamma Sorority House.                        " << endl
    << "The plantation-styled house is well manicured. The lawn is freshly cut and the" << endl
    << "shrubs surrounding the house give it a spring-time feeling. The giant, painted" << endl
    << "Greek letters out front indicate that this is a \"Girls Only\" area. The rest " << endl
    << "of campus is not visible from here, but the people hanging around it make it  " << endl
    << "obvious this is still on-campus.                                              " << endl;
}



// Room B-1.
void DescribeRoomB1()
{
    cout << "You stand in the door of the Cafeteria.                                        " << endl
    << "You instantly feel comforatable as the surroundings are cozy. The walls and    " << endl
    << "ceilings are all mahogony and the carpet has a complex pattern upon it. The    " << endl
    << "tables and chairs also appear to be mahogony, and the chandeliers have an      " << endl
    << "almost renaissance appearance. Portraits of the college's previous presidents  " << endl
    << "stare at the students from the walls. Students are spread out, either enjoying " << endl
    << "their meals with company or cramming a meal and study session into one sitting." << endl;
}


// Room B-2.
void DescribeRoomB2()
{
    cout << "You are standing on South University Street.                                       " << endl
    << "The surrounding environment is modeled after Oxford. You can see students strolling" << endl
    << "along the sidewalks peacefully, and others sprinting to their next class. There is " << endl
    << "little to no shade on this part of University Street. You feel the Sun's heat      " << endl
    << "beating against the back of your neck. Maybe it's best to get moving before you    " << endl
    << "start sweating.                                                                    " << endl;
}


// Room B-3.
void DescribeRoomB3()
{
    cout << "You are outside of the Campus Safety Office.                                        " << endl
    << "The building does not match the other buildings on campus. It is a two-story brick  " << endl
    << "building with a black roof. You can see the high-tech equipment they use inside the " << endl
    << "building. Though the building is plain and uninteresting, what goes on inside scares" << endl
    << "even the most daring students.                                                      " << endl;
}


// Room B-4.
void DescribeRoomB4()
{
    cout << "You are pulled over on the Interstate.                                              " << endl
    << "It is dark outside, but the skies are clear allowing for the stars and full moon to " << endl
    << "be visible. There are tall, eery trees on either side of the road. The smooth road  " << endl
    << "is empty, but you can hear civilization nearby. The surrounding environment is calm," << endl
    << "even in all of its mystery...                                                       " << endl;
}


// Room B-5.
void DescribeRoomB5()
{
    cout << "You are on the campus of Emily Dickenson College.                                 " << endl
    << "It is similar in design to Faber College. However, it is an all-girl college. It  " << endl
    << "is a little smaller than Faber College, so it is easier to see the majority of the" << endl
    << "campus from where you are standing. The campus is well-kept and the surrounding   " << endl
    << "mood is less stressful than Faber College. Too bad you can't go to school here.   " << endl;
}



// Room C-1.
void DescribeRoomC1()
{
    cout << "You are standing inside Dean Wormer's Office.                                       " << endl
    << "Everything is mahogony and it smells of cedar wood. There is a fully stocked bar in " << endl
    << "one corner underneath a painting of George Washington taking the oath of office.    " << endl
    << "Behind the Dean's desk on the walls are his degrees from the accredited \"University" << endl
    << "of Phoenix\" and \"ITT Technical Institute.\" You notice beside the red curtains in " << endl
    << "the back-left of the room a secret door. It leads to the Dean's private bathroom.   " << endl
    << "The school obviously spends a lot of money on accomidating Dean Wormer...           " << endl;
}


// Room C-2.
void DescribeRoomC2()
{
    cout << "You are standing on Academic Lane.                                                      " << endl
    << "Much like the rest of campus, this street attempts to resemble the academic excellence  " << endl
    << "of Oxford. There is not a single leaf on the surrounding lawns, the trash cans are never" << endl
    << "over-flowing, and the only thing that seems out of place are the student organizations  " << endl
    << "with information tables set up on the far sides of the street. There are spots of shade " << endl
    << "for students to study, picnic, and relax. It serves as a divider between the serious and" << endl
    << "care-free parts of Faber College.                                                       " << endl;
}


// Room C-3.
void DescribeRoomC3()
{
    cout << "You are inside the Academic Building.                                                         " << endl
    << "The high ceilings are a dark, rich mahogony with ancient chandeliers hanging to provide light " << endl
    << "to the main hall. Though the appearance is old and prestigious, the classrooms that line the  " << endl
    << "halls appear ultra-modern. There is a Starbucks look-a-like coffee shop down the main hall, as" << endl
    << "well as several unhealthy vending machines packed with energy drinks and sugary snacks. The   " << endl
    << "hall is empty, but almost every classroom is full. It is somewhat quiet, but if you listen    " << endl
    << "hard enough you can hear classroom discussions on various academic topics. This is where you  " << endl
    << "convinced your parents you would be spending the majority of your time...                     " << endl;
}


// Room C-4.
void DescribeRoomC4()
{
    cout << "You are pulled over on the Interstate.                                                " << endl
    << "It is dark outside, but the skies are clear allowing for the stars and full moon to   " << endl
    << "be visible. There are tall, eery trees on either side of the road. The road is old and" << endl
    << "rough, and there are construction signs on the other side of the road. All is silent  " << endl
    << "except for the crickets chirping and the occasional owl hooting...                    " << endl;
}


// Room C-5.
void DescribeRoomC5()
{
    cout << "You are parked on the side of Shady Road.                                             " << endl
    << "The road is old and has several pot holes. It is obvious it did not get its name from " << endl
    << "the shade on and around the road; there are no trees in sight. It embodies the stereo-" << endl
    << "typical appearance of a Midwest highway. The grass on either side is tall, the road is" << endl
    << "flat, and you can see a tumbleweed blow across the road.                              " << endl;
}



// Room D-1.
void DescribeRoomD1()
{
    cout << "You are in the Secret Initiation Room." << endl
    << "Everything is dark because you are blindfolded. You can hear torches burning and " << endl
    << "someone is chanting in latin... Only the initiated may see this room!            " << endl;
}


// Room D-2.
void DescribeRoomD2()
{
    cout << "You are standing on Secrets Boulevard.                                              " << endl
    << "Though this street and the surrounding area appear similar to the other streets on  " << endl
    << "campus, it is almost devoid of any activity. On either side of the street are very  " << endl
    << "tall trees and bushes. Students of the college avoid this part of campus as much as " << endl
    << "possible. The few students you see have their heads down and are walking at a very  " << endl
    << "fast pace. According to legend, the college's first fraternity once stood on the    " << endl
    << "street during the Civil War. However, Union soldiers used it as a torture house when" << endl
    << "they took refuge on the campus. Those who were victims of the torture house haunt   " << endl
    << "the area as they cannot find peace... You suddenly feel an unusually chilly breeze  " << endl
    << "and realize you have been standing around for far too long...                       " << endl;
}


// Room D-3.
void DescribeRoomD3()
{
    cout << "You are standing in Gregory Marmalard's Room.                          " << endl
    << "It looks like something out of an IKEA or Skymall. Everything is sleek " << endl
    << "and ultra-modern. The walls are just off-white, the ceiling is black,  " << endl
    << "and the floors are an expensive, white marble. His king-sized water bed" << endl
    << "is in the center of the room, and what appears to be an office space is" << endl
    << "facing the opposite direction of his \"entertainment center.\" All of  " << endl
    << "this makes Gregory seem extremely sophistocated, but he is clearly     " << endl
    << "compensating for something...                                          " << endl;
}


// Room D-4.
void DescribeRoomD4()
{
    cout << "You just drove into the Local Town.                                            " << endl
    << "You are parked at the town square. In the center is the town's courthouse. You " << endl
    << "see a large, marble statue of a Civil War veteran in front of where you are    " << endl
    << "parked. Though it has all of the markings of a college town, its population    " << endl
    << "mostly consists of old people who couldn't leave the peaceful environment. The " << endl
    << "buildings around the square and in the surrounding area reflect the population." << endl
    << "Though most students at Faber College claim the town is a worn down relic of   " << endl
    << "the past, you can sense something majestic in its age. You hear a train whistle" << endl
    << "from afar a reminder of the past glory the town held before the interstate     " << endl
    << "system was constructed.                                                        " << endl;
}


// Room D-5.
void DescribeRoomD5()
{
    cout << "You are on the Secluded Farm.                                      " << endl
    << "There is a small, worn-out barn at the other end of the decrepit   " << endl
    << "pasture. The farm is abandoned and the moonlight gives it a haunted" << endl
    << "appearance. You feel shivers running down your spine. Maybe you    " << endl
    << "should leave the area...                                           " << endl;
}


// Room E-1.
void DescribeRoomE1()
{
    cout << "You are inside the Delta Tau Chi House.                          " << endl
    << "To an outsider, the large house may seem run down and awaiting   " << endl
    << "demolition. The paint is chipping, some shingles are missing     " << endl
    << "from the roof, the grounds are unkempt, and the porch is uneven. " << endl
    << "But this is your new home. You see all of the potential for great" << endl
    << "parties and even better memories...                              " << endl;
}



// Room E-2.
void DescribeRoomE2()
{
    cout << "You are standing on Fraternity Row.                          " << endl
    << "It is obvious you are on the more unkempt part of campus.    " << endl
    << "Beer cans and broken bottles are scattered about the street. " << endl
    << "This may be the least attractive part of campus, but it is   " << endl
    << "clearly where all students go to blow off steam and have fun." << endl;
}


// Room E-3.
void DescribeRoomE3()
{
    cout << "You are inside the Omega Theta Pi House." << endl
    << "The three-story brick house has the appearance of an elite fraternity" << endl
    << "house. There is a large pool in the back, a bricked driveway, and a  " << endl
    << "well-manicured lawn. Its white pillars are spotless and their letters" << endl
    << "are painted on the top balcony in gold. You see the house dog sitting" << endl
    << "on the porch. It's a well trained black lab that they shamelessly use" << endl
    << "to lure girls to hang around them. The whole environment screams of  " << endl
    << "\"try-hards.\" You know that they have nicer things than the Deltas, " << endl
    << "but you also know that they do not share as close of a bond as you do" << endl
    << "with your brothers. They'll get what is coming to them soon enough.  " << endl;
}


// Room E-4.
void DescribeRoomE4()
{
    cout << "You are standing on Sketchy Drive." << endl
    << "The area is just outside of civilization, but the tall corn fields on either  " << endl
    << "side of the road indicate that you aren't that far from people. The full moon " << endl
    << "lights the corn in a peaceful way. The dirt road has a rich, orange glow. You " << endl
    << "can see an orange dust trail behind where you have driven. As you are parked, " << endl
    << "you see the corn stalks to your right shake and then you hear a coyote howl..." << endl;
}


// Room E-5.
void DescribeRoomE5()
{
    cout << "You are inside the Mini-Mart." << endl
    << "The store resembles a sketchy gas station. It is lit by dying       " << endl
    << "flourescent lightbulbs. You can't see the walls as they are covered " << endl
    << "covered with cheap beer, wine, and spirits. It is obvious what type " << endl
    << "of custormer the store caters to as it is near two college campuses." << endl;
}

//***************************************************************************************************

// Build each room by ORing together the contents.

void BuildRooms(unsigned int rooms[][5])
{
// Build Room A1.
    rooms[0][0] = DOOR_EAST | PLEDGE_BOOK_SIGNED;
// Build Room A2.
    rooms[0][1] = DOOR_EAST | DOOR_SOUTH | DOOR_WEST | CAMPUS_SAFETY_OFFICER | DANGEROUS;
// Build Room A3.
    rooms[0][2] = DOOR_EAST | DOOR_SOUTH | DOOR_WEST;
// Build Room A4.
    rooms[0][3] = DOOR_SOUTH | DOOR_WEST;
// Build Room A5.
    rooms[0][4] = DOOR_SOUTH | ANGRY_GAMMA_SORORITY_GIRL | CAUTION;
    
// Build Room B1.
    rooms[1][0] = DOOR_EAST | ANTI_GREEK_LIFE_STUDENT | CAUTION;
// Build Room B2.
    rooms[1][1] = DOOR_NORTH | DOOR_EAST | DOOR_SOUTH | DOOR_WEST | CAMPUS_SAFETY_OFFICER | DANGEROUS;
// Build Room B3.
    rooms[1][2] = DOOR_NORTH | DOOR_SOUTH | DOOR_WEST | OFFICER_JOHNNY_AUSTIN | DEADLY;
// Build Room B4.
    rooms[1][3] = DOOR_NORTH | DOOR_SOUTH;
// Build Room B5.
    rooms[1][4] = DOOR_NORTH | DOOR_SOUTH | CAMPUS_SAFETY_OFFICER;
    
// Build Room C1.
    rooms[2][0] = DOOR_EAST | DEAN_VERNON_WORMER | DEADLY;
// Build Room C2.
    rooms[2][1] = DOOR_NORTH | DOOR_EAST | DOOR_SOUTH | DOOR_WEST | ANTI_GREEK_LIFE_STUDENT | CAUTION;
// Build Room C3.
    rooms[2][2] = DOOR_NORTH | DOOR_WEST;
// Build Room C4.
    rooms[2][3] = DOOR_NORTH | DOOR_EAST | DOOR_SOUTH;
// Build Room C5.
    rooms[2][4] = DOOR_NORTH | DOOR_SOUTH | DOOR_WEST;
    
// Build Room D1.
    rooms[3][0] = DOOR_SOUTH;
// Build Room D2.
    rooms[3][1] = DOOR_NORTH | DOOR_SOUTH;
// Build Room D3.
    rooms[3][2] = DOOR_SOUTH | GREGORY_MARMALARD | DEADLY | OMEGA_THETA_PI_RITUAL_BOOK;
// Build Room D4.
    rooms[3][3] = DOOR_NORTH | DOOR_SOUTH;
// Build Room D5.
    rooms[3][4] = DOOR_NORTH | THE_GOAT;
    
// Build Room E1.
    rooms[4][0] = DOOR_NORTH | DOOR_EAST | PLEDGE_MASTER_CHIP;
// Build Room E2.
    rooms[4][1] = DOOR_NORTH | DOOR_EAST | DOOR_WEST;
// Build Room E3.
    rooms[4][2] = DOOR_NORTH | DOOR_WEST | OMEGA_THETA_PI_MEMBER | CAUTION;
// Build Room E4.
    rooms[4][3] = DOOR_NORTH | DOOR_EAST | HIPPY | FRIENDLY;
// Build Room E5.
    rooms[4][4] = DOOR_WEST;
    
    
    
}

//****************************************************************************
// Take an object.
// Args:    rooms- 2D array of unsigned int defining contents of all rooms.
//          row- index of row of room player is now in.
//          col- index of column of room player is now in.
//          Object- string naming the object the player wants to TAKE.
//****************************************************************************

int TakeItem(unsigned int rooms[5][5], int row, int col, string Object)
{
// Is player trying to take the sacred GOAT?
    if((Object == "GOAT") && (rooms[row][col] & THE_GOAT))
    {
        rooms[row][col] ^= THE_GOAT;    // Use XOR (^) to clear this bit in this room.
        return THE_GOAT;                // Return appropriate flag for this item.
    }
// Is player trying to take the omega theta pi ritual BOOK?
    if((Object == "BOOK") && (rooms[row][col] & OMEGA_THETA_PI_RITUAL_BOOK))
    {
        rooms[row][col] ^= OMEGA_THETA_PI_RITUAL_BOOK;  // Use XOR (^) to clear this bit in this room.
        return OMEGA_THETA_PI_RITUAL_BOOK;              // Return appropriate flag for this item.
    }
// Is player trying to take their signed pledge BOOK?
    if((Object == "BOOK") && (rooms[row][col] & PLEDGE_BOOK_SIGNED))
    {
        rooms[row][col] ^= PLEDGE_BOOK_SIGNED;      // Use XOR (^) to clear this bit in this room.
        return PLEDGE_BOOK_SIGNED;                  // Return appropriate flag for this item.
    }
// Is player trying to take the pledge master's CHIP?
    if((Object == "CHIP") && (rooms[row][col] & PLEDGE_MASTER_CHIP))
    {
        rooms[row][col] ^= PLEDGE_MASTER_CHIP;      // Use XOR (^) to clear this bit in this room.
        return PLEDGE_MASTER_CHIP;                  // Return appropriate flag for this item.
    }
    
    
// To allow the user to take anything else from a room, add the checks here as
// more "else if" blocks.
    
    
    return 0;   // Didn't find object to TAKE so return zero.
}

