#include "BehaviourTree.h"


int main() {
	Sequence *root = new Sequence, *sequence1 = new Sequence;	// Note that root can be either a Sequence or a Selector, since it has only one child.
	Selector* selector1 = new Selector;							// In general there will be several nodes that are Sequence or Selector, so they should be suffixed by an integer to distinguish between them.
	DoorStatus* doorStatus = new DoorStatus{ false, 5 };		// The door is initially closed and 5 meters away.
	CheckIfDoorIsOpenTask* checkOpen = new CheckIfDoorIsOpenTask(doorStatus);
	ApproachDoorTask* approach = new ApproachDoorTask(doorStatus, false);
	OpenDoorTask* open = new OpenDoorTask(doorStatus);

	root->addChild(selector1);

	selector1->addChild(checkOpen);
	selector1->addChild(sequence1);

	sequence1->addChild(approach);
	sequence1->addChild(open);

	while (!root->run())  // If the operation starting from the root fails, keep trying until it succeeds.
		std::cout << "--------------------" << std::endl;
	std::cout << std::endl << "Operation complete.  Behaviour tree exited." << std::endl;
	std::cin.get();
}

/*
Output:
The person sees that the door is closed.
The person approaches the door.
The person is now 4 meters from the door.
The person is still too far away from the door.  He cannot open the door.
--------------------
The person sees that the door is closed.
The person approaches the door.
The person is now 3 meters from the door.
The person is still too far away from the door.  He cannot open the door.
--------------------
The person sees that the door is closed.
The person approaches the door.
The person is now 2 meters from the door.
The person is still too far away from the door.  He cannot open the door.
--------------------
The person sees that the door is closed.
The person approaches the door.
The person is now only one meter away from the door.
The person is still too far away from the door.  He cannot open the door.
--------------------
The person sees that the door is closed.
The person approaches the door.
The person is at the door.
The person opens the door.

Operation complete.  Behaviour tree exited.
*/

