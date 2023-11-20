// File Line: 33
// RVA: 0x5BDB00
void __fastcall UFG::UIScreenFactoryBase::~UIScreenFactoryBase(UFG::UIScreenFactoryBase *this)
{
  this->vfptr = (UFG::UIScreenFactoryBaseVtbl *)&UFG::UIScreenFactoryBase::`vftable';
}

// File Line: 46
// RVA: 0x5C3570
UFG::allocator::free_link *__fastcall UFG::UIScreenFactoryWrapper<UFG::UIHKScreenScriptableList>::create(UFG::UIScreenFactoryWrapper<UFG::UIHKScreenScriptableList> *this)
{
  UFG::allocator::free_link *result; // rax
  UFG::allocator::free_link *v2; // rcx
  UFG::allocator::free_link *v3; // rax

  result = UFG::qMemoryPool::Allocate(&gScaleformMemoryPool, 0x90ui64, "UIScreenFactoryWrapper", 0i64, 1u);
  v2 = result;
  if ( result )
  {
    v3 = result + 1;
    v3->mNext = v3;
    v3[1].mNext = v3;
    v2->mNext = (UFG::allocator::free_link *)&UFG::UIScreen::`vftable';
    LODWORD(v2[11].mNext) = 0;
    v2[12].mNext = 0i64;
    v2[13].mNext = 0i64;
    LODWORD(v2[14].mNext) = -1;
    *(UFG::allocator::free_link **)((char *)&v2[14].mNext + 4) = (UFG::allocator::free_link *)15;
    *(UFG::allocator::free_link **)((char *)&v2[15].mNext + 4) = 0i64;
    HIDWORD(v2[16].mNext) = 0;
    v2[17].mNext = (UFG::allocator::free_link *)1120403456;
    LOBYTE(v2[3].mNext) = 0;
    --LODWORD(v2[15].mNext);
    v2->mNext = (UFG::allocator::free_link *)&UFG::UIHKScreenScriptableList::`vftable';
    result = v2;
  }
  return result;
}

