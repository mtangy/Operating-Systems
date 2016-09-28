
void
ProcessSchedule ()
{
  PCB           *pcb;
  int           i;
  int winner;     //winning ticket drawn
  int curTicket;  //sum of traversed tickets 
  

  dbprintf ('p', "Now entering ProcessSchedule (cur=0x%x, %d ready)\n",
            currentPCB, QueueLength (&runQueue));
  // The OS exits if there's no runnable process.  This is a feature, not a
  // bug.  An easy solution to allowing no runnable "user" processes is to
  // have an "idle" process that's simply an infinite loop.
  if (QueueEmpty (&runQueue)) {
    printf ("No runnable processes - exiting!\n");
    exitsim (); // NEVER RETURNS
  }

  // Move the front of the queue to the end, if it is the running process.

  pcb = (PCB *)((QueueFirst (&runQueue))->object);
  if (pcb == currentPCB)
  {
    QueueRemove (&pcb->l);
    QueueInsertLast (&runQueue, &pcb->l);
  }
///////////////////////ROUND ROBIN METHOD//////////////////////////
// Now, run the one at the head of the queue.
//  pcb = (PCB *)((QueueFirst (&runQueue))->object);
//  currentPCB = pcb;
//  dbprintf ('p',"About to switch to PCB 0x%x,flags=0x%x @ 0x%x\n",
//            pcb, pcb->flags,
//            pcb->sysStackPtr[PROCESS_STACK_IAR]);
///////////////////////////////////////////////////////////////////
///////////////////////LOTTERY METHOD//////////////////////////////
winner = (random() % total_tickets);





////////////////////////////////////////////////////////////////////
  // Clean up zombie processes here.  This is done at interrupt time
  // because it can't be done while the process might still be running
  while (!QueueEmpty (&zombieQueue)) {
    pcb = (PCB *)(QueueFirst (&zombieQueue)->object);
    dbprintf ('p', "Freeing zombie PCB 0x%x.\n", pcb);
    QueueRemove (&pcb->l);
    ProcessFreeResources (pcb);
  }
  // Set the timer so this process gets at most a fixed quantum of time.
  TimerSet (processQuantum);
  dbprintf ('p', "Leaving ProcessSchedule (cur=0x%x)\n", currentPCB);
}
