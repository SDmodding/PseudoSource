// File Line: 37
// RVA: 0xA38C70
UFG::qSpuManager *__fastcall UFG::qSpuManager::Instance()
{
  if ( !(_S2_13 & 1) )
    _S2_13 |= 1u;
  return &sSpuManagerInstance;
}

// File Line: 43
// RVA: 0xA38A50
UFG::qList<UFG::qSpuElf,UFG::qSpuElf,1,0> *__fastcall UFG::qSpuManager::GetSpuElfList(UFG::qSpuManager *this)
{
  if ( !(_S3_8 & 1) )
  {
    _S3_8 |= 1u;
    sSpuElfList.mNode.mPrev = (UFG::qNode<UFG::qSpuElf,UFG::qSpuElf> *)&sSpuElfList;
    sSpuElfList.mNode.mNext = (UFG::qNode<UFG::qSpuElf,UFG::qSpuElf> *)&sSpuElfList;
    atexit(UFG::qSpuManager::GetSpuElfList_::_2_::_dynamic_atexit_destructor_for__sSpuElfList__);
  }
  return &sSpuElfList;
}

