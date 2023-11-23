// File Line: 27
// RVA: 0x18EEF0
void UFG::QuarkProbe::Init(void)
{
  UFG::qList<UFG::qPrintChannel,UFG::qPrintChannel,1,0> *PrintChannelList; // rax
  UFG::qList<UFG::qPrintChannel,UFG::qPrintChannel,1,0> *i; // rcx

  PrintChannelList = UFG::qGetPrintChannelList();
  for ( i = (UFG::qList<UFG::qPrintChannel,UFG::qPrintChannel,1,0> *)PrintChannelList->mNode.mNext;
        i != PrintChannelList;
        i = (UFG::qList<UFG::qPrintChannel,UFG::qPrintChannel,1,0> *)i->mNode.mNext )
  {
    ;
  }
}

