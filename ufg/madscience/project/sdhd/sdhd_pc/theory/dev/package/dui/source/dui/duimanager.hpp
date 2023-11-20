// File Line: 175
// RVA: 0x158380
UFG::qSafePointer<UFG::DUIWindow,UFG::DUIWindow> *__fastcall UFG::DUIManager::CreateWindow(UFG::DUIManager *this, UFG::qSafePointer<UFG::DUIWindow,UFG::DUIWindow> *result, const char *type_name, const char *context_name, const char *group_tag)
{
  UFG::qSafePointer<UFG::DUIWindow,UFG::DUIWindow> *v5; // rbx
  UFG::DUIWindow *v6; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::DUIWindow>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::DUIWindow>,UFG::qSafePointerNodeList> *v8; // rax

  v5 = result;
  v6 = UFG::DUIManager::CreateWindowInternal(this, type_name, context_name, group_tag);
  v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::DUIWindow>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  v5->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::DUIWindow>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  v5->m_pPointer = v6;
  if ( v6 )
  {
    v7 = &v6->m_SafePointerList.mNode;
    v8 = v6->m_SafePointerList.mNode.mPrev;
    v8->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::DUIWindow>,UFG::qSafePointerNodeList> *)&v5->mPrev;
    v5->mPrev = v8;
    v5->mNext = v7;
    v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::DUIWindow>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  }
  return v5;
}

