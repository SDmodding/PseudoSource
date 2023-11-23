// File Line: 30
// RVA: 0xA23750
void __fastcall UFG::UIScreenFactory::UIScreenFactory(UFG::UIScreenFactory *this)
{
  this->vfptr = (UFG::UIScreenFactoryVtbl *)&UFG::UIScreenFactory::`vftable;
  UFG::qBaseTreeRB::qBaseTreeRB(&this->m_factoryList.mTree);
}

// File Line: 37
// RVA: 0xA23E90
void __fastcall UFG::UIScreenFactory::~UIScreenFactory(UFG::UIScreenFactory *this)
{
  UFG::qTreeRB<UFG::UIScreenFactoryNode,UFG::UIScreenFactoryNode,1> *p_m_factoryList; // rbx

  this->vfptr = (UFG::UIScreenFactoryVtbl *)&UFG::UIScreenFactory::`vftable;
  p_m_factoryList = &this->m_factoryList;
  UFG::qTreeRB<UFG::UIScreenFactoryNode,UFG::UIScreenFactoryNode,1>::DeleteAll(&this->m_factoryList);
  UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)p_m_factoryList);
}

// File Line: 46
// RVA: 0xA2A6E0
UFG::allocator::free_link *__fastcall UFG::UIScreenFactory::createScreen(UFG::UIScreenFactory *this, const char *name)
{
  unsigned int v3; // eax
  UFG::qBaseTreeRB *v4; // rax
  UFG::qBaseNodeRB *mParent; // rcx
  UFG::allocator::free_link *v7; // rax
  UFG::allocator::free_link *v8; // rcx
  UFG::allocator::free_link *v9; // rax

  v3 = UFG::qStringHashUpper32(name, -1);
  if ( v3 )
  {
    v4 = UFG::qBaseTreeRB::Get(&this->m_factoryList.mTree, v3);
    if ( v4 )
    {
      mParent = v4->mNULL.mParent;
      if ( mParent )
        return (UFG::allocator::free_link *)((__int64 (__fastcall *)(UFG::qBaseNodeRB *))mParent->mParent->mParent)(mParent);
    }
  }
  v7 = UFG::qMemoryPool::Allocate(&gScaleformMemoryPool, 0x90ui64, "UIScreenFactory::UIScreen", 0i64, 1u);
  v8 = v7;
  if ( !v7 )
    return 0i64;
  v9 = v7 + 1;
  v9->mNext = v9;
  v9[1].mNext = v9;
  v8->mNext = (UFG::allocator::free_link *)&UFG::UIScreen::`vftable;
  LODWORD(v8[11].mNext) = 0;
  v8[12].mNext = 0i64;
  v8[13].mNext = 0i64;
  LODWORD(v8[14].mNext) = -1;
  *(UFG::allocator::free_link **)((char *)&v8[14].mNext + 4) = (UFG::allocator::free_link *)15;
  *(UFG::allocator::free_link **)((char *)&v8[15].mNext + 4) = 0i64;
  HIDWORD(v8[16].mNext) = 0;
  v8[17].mNext = (UFG::allocator::free_link *)1120403456;
  LOBYTE(v8[3].mNext) = 0;
  --LODWORD(v8[15].mNext);
  return v8;
}

// File Line: 75
// RVA: 0xA292F0
void __fastcall UFG::UIScreenFactory::addScreenMapping(
        UFG::UIScreenFactory *this,
        const char *name,
        UFG::qBaseNodeRB *factory)
{
  UFG::qBaseNodeRB *v6; // rbx
  unsigned int v7; // eax

  v6 = (UFG::qBaseNodeRB *)UFG::qMemoryPool::Allocate(
                             &gScaleformMemoryPool,
                             0x28ui64,
                             "UIScreenFactory::UIScreenFactoryNode",
                             0i64,
                             1u);
  if ( v6 )
  {
    v7 = UFG::qStringHashUpper32(name, -1);
    v6->mParent = 0i64;
    v6->mChild[0] = 0i64;
    v6->mChild[1] = 0i64;
    v6->mUID = v7;
    v6[1].mParent = factory;
  }
  else
  {
    v6 = 0i64;
  }
  UFG::qBaseTreeRB::Add(&this->m_factoryList.mTree, v6);
}

