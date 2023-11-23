// File Line: 33
// RVA: 0x5BDB00
void __fastcall UFG::UIScreenFactoryBase::~UIScreenFactoryBase(UFG::UIScreenFactoryBase *this)
{
  this->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryBase::`vftable;
}

// File Line: 46
// RVA: 0x5C3570
UFG::allocator::free_link *__fastcall UFG::UIScreenFactoryWrapper<UFG::UIHKScreenScriptableList>::create(
        UFG::UIScreenFactoryWrapper<UFG::UIHKScreenScriptableList> *this)
{
  UFG::allocator::free_link *result; // rax
  UFG::UIScreen *v2; // rcx
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v3; // rax

  result = UFG::qMemoryPool::Allocate(&gScaleformMemoryPool, 0x90ui64, "UIScreenFactoryWrapper", 0i64, 1u);
  v2 = (UFG::UIScreen *)result;
  if ( result )
  {
    v3 = (UFG::qNode<UFG::UIScreen,UFG::UIScreen> *)&result[1];
    v3->mPrev = v3;
    v3->mNext = v3;
    v2->vfptr = (UFG::UIScreenVtbl *)&UFG::UIScreen::`vftable;
    v2->m_screenNameHash = 0;
    v2->mRenderable = 0i64;
    v2->mLoadThread = 0i64;
    v2->mScreenUID = -1;
    *(_QWORD *)&v2->mControllerMask = 15i64;
    *(_QWORD *)&v2->mPriority = 0i64;
    v2->mDimToApplyType = eDIM_INVALID;
    *(_QWORD *)&v2->mCurDimValue = 1120403456i64;
    v2->m_screenName[0] = 0;
    --v2->mInputEnabled;
    v2->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenScriptableList::`vftable;
    return (UFG::allocator::free_link *)v2;
  }
  return result;
}

