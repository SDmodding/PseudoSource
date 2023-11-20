// File Line: 27
// RVA: 0x18EEF0
void UFG::QuarkProbe::Init(void)
{
  UFG::qList<UFG::qPrintChannel,UFG::qPrintChannel,1,0> *v0; // rax
  UFG::qList<UFG::qPrintChannel,UFG::qPrintChannel,1,0> *i; // rcx

  v0 = UFG::qGetPrintChannelList();
  for ( i = (UFG::qList<UFG::qPrintChannel,UFG::qPrintChannel,1,0> *)v0->mNode.mNext;
        i != v0;
        i = (UFG::qList<UFG::qPrintChannel,UFG::qPrintChannel,1,0> *)i->mNode.mNext )
  {
    ;
  }
}

