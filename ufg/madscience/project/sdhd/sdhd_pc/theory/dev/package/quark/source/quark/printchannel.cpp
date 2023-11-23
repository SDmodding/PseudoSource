// File Line: 38
// RVA: 0x184AE0
UFG::qList<UFG::qPrintChannel,UFG::qPrintChannel,1,0> *__fastcall UFG::qGetPrintChannelList()
{
  if ( (_S7_4 & 1) == 0 )
  {
    _S7_4 |= 1u;
    sPrintChannelList.mNode.mPrev = (UFG::qNode<UFG::qPrintChannel,UFG::qPrintChannel> *)&sPrintChannelList;
    sPrintChannelList.mNode.mNext = (UFG::qNode<UFG::qPrintChannel,UFG::qPrintChannel> *)&sPrintChannelList;
    atexit(UFG::qGetPrintChannelList_::_2_::_dynamic_atexit_destructor_for__sPrintChannelList__);
  }
  return &sPrintChannelList;
}

