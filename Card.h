enum Status
{
	TODO, DOING, DONE
};

struct Card {
    /**
     * kartya egyedi azonositoja
     */
	int id;
	/**
	 * kartya neve
	 */
	char taskName[100];
	/**
	 * kartya statusza
	 */
	enum Status status;
	/**
	 * szemely id ja
	 */
	int personId;
	/**
	 * regebbi szemelyek idjai
	 */
	int pastWorkers[100];
};