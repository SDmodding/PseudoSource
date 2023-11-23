// File Line: 175
// RVA: 0x158380
UFG::qSafePointer<UFG::DUIWindow,UFG::DUIWindow> *__fastcall UFG::DUIManager::CreateWindow(
        UFG::DUIManager *this,
        UFG::qSafePointer<UFG::DUIWindow,UFG::DUIWindow> *result,
        const char *type_name,
        const char *context_name,
        const char *group_tag)
{
  UFG::DUIWindow *WindowInternal; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::DUIWindow>,UFG::qSafePointerNodeList> *p_mNode; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::DUIWindow>,UFG::qSafePointerNodeList> *mPrev; // rax

  WindowInternal = UFG::DUIManager::CreateWindowInternal(this, type_name, context_name, group_tag);
  result->mPrev = result;
  result->mNext = result;
  result->m_pPointer = WindowInternal;
  if ( WindowInternal )
  {
    p_mNode = &WindowInternal->m_SafePointerList.mNode;
    mPrev = WindowInternal->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::DUIWindow>::mPrev;
    mPrev->mNext = result;
    result->mPrev = mPrev;
    result->mNext = p_mNode;
    p_mNode->mPrev = result;
  }
  return result;
}

