// File Line: 36
// RVA: 0xFA880
void __fastcall UFG::AvoidPairInstance::AvoidPairInstance(UFG::AvoidPairInstance *this)
{
  UFG::AvoidPairInstance *v1; // r9
  UFG::qSafePointer<UFG::FlowfieldPrint,UFG::FlowfieldPrint> *v2; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::AIInterestComponent> *v3; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *v4; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *v5; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax

  v1 = this;
  v2 = &this->mFieldPrint;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  this->mFieldPrint.m_pPointer = 0i64;
  v3 = &this->mAvoidable;
  v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  v3->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  this->mAvoidable.m_pPointer = 0i64;
  if ( this->mFieldPrint.m_pPointer )
  {
    v4 = v2->mPrev;
    v5 = v2->mNext;
    v4->mNext = v5;
    v5->mPrev = v4;
    v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  }
  v2->m_pPointer = 0i64;
  if ( v3->m_pPointer )
  {
    v6 = v3->mPrev;
    v7 = v3->mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
    v3->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  }
  v3->m_pPointer = 0i64;
  v1->mbDeleteFieldPrint = 0;
  *(_QWORD *)&v1->mScore = 0i64;
}

// File Line: 55
// RVA: 0xFBA50
void __fastcall UFG::AvoidPairInstance::~AvoidPairInstance(UFG::AvoidPairInstance *this)
{
  UFG::AvoidPairInstance *v1; // rbx
  UFG::qSafePointer<UFG::SimComponent,UFG::AIInterestComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::FlowfieldPrint,UFG::FlowfieldPrint> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *v11; // rax

  v1 = this;
  UFG::AvoidPairInstance::Clear(this);
  v2 = &v1->mAvoidable;
  if ( v1->mAvoidable.m_pPointer )
  {
    v3 = v2->mPrev;
    v4 = v1->mAvoidable.mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    v1->mAvoidable.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mAvoidable.mPrev;
  }
  v1->mAvoidable.m_pPointer = 0i64;
  v5 = v2->mPrev;
  v6 = v1->mAvoidable.mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v1->mAvoidable.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mAvoidable.mPrev;
  v7 = &v1->mFieldPrint;
  if ( v1->mFieldPrint.m_pPointer )
  {
    v8 = v7->mPrev;
    v9 = v1->mFieldPrint.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v1->mFieldPrint.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *)&v1->mFieldPrint.mPrev;
  }
  v1->mFieldPrint.m_pPointer = 0i64;
  v10 = v7->mPrev;
  v11 = v1->mFieldPrint.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v1->mFieldPrint.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *)&v1->mFieldPrint.mPrev;
}

// File Line: 59
// RVA: 0xFCCF0
void __fastcall UFG::AvoidPairInstance::Clear(UFG::AvoidPairInstance *this)
{
  UFG::AvoidPairInstance *v1; // rbx
  UFG::FlowfieldPrint *v2; // rcx
  UFG::FlowfieldPrint *v3; // rax
  UFG::qSafePointer<UFG::FlowfieldPrint,UFG::FlowfieldPrint> *v4; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AIInterestComponent> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax

  v1 = this;
  if ( this->mbDeleteFieldPrint && (v2 = this->mFieldPrint.m_pPointer) != 0i64 )
  {
    v2->vfptr->__vecDelDtor((UFG::qSafePointerNode<UFG::FlowfieldPrint> *)&v2->vfptr, 1u);
  }
  else
  {
    v3 = v1->mFieldPrint.m_pPointer;
    if ( v3 )
      v3->m_Enabled = 0;
  }
  v4 = &v1->mFieldPrint;
  if ( v1->mFieldPrint.m_pPointer )
  {
    v5 = v4->mPrev;
    v6 = v1->mFieldPrint.mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *)&v4->mPrev;
    v1->mFieldPrint.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *)&v1->mFieldPrint.mPrev;
  }
  v1->mFieldPrint.m_pPointer = 0i64;
  v7 = &v1->mAvoidable;
  if ( v1->mAvoidable.m_pPointer )
  {
    v8 = v7->mPrev;
    v9 = v1->mAvoidable.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v1->mAvoidable.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mAvoidable.mPrev;
  }
  v1->mAvoidable.m_pPointer = 0i64;
  v1->mbDeleteFieldPrint = 0;
  *(_QWORD *)&v1->mScore = 0i64;
}

// File Line: 72
// RVA: 0x100240
void __fastcall UFG::AvoidPairInstance::Init(UFG::AvoidPairInstance *this, UFG::SimObject *pParent, UFG::AIInterestComponent *pAvoidable)
{
  UFG::AIInterestComponent *v3; // rdi
  UFG::AvoidPairInstance *v4; // rsi
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // r10
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::SimComponent *v9; // rax
  __int64 v10; // r8
  UFG::SimComponent *v11; // r14
  UFG::FlowfieldPrint *v12; // rbx
  char *v13; // rax
  __int64 v14; // r8
  UFG::FlowfieldPrint *v15; // rax
  UFG::qSafePointer<UFG::FlowfieldPrint,UFG::FlowfieldPrint> *v16; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *v17; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *v18; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::qSafePointer<UFG::FlowfieldPrint,UFG::FlowfieldPrint> *v20; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *v21; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *v22; // rax

  v3 = pAvoidable;
  v4 = this;
  this->mAge = 0.000099999997;
  v5 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&this->mAvoidable.mPrev;
  if ( this->mAvoidable.m_pPointer )
  {
    v6 = v5->mPrev;
    v7 = this->mAvoidable.mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    v5->mPrev = v5;
    this->mAvoidable.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&this->mAvoidable.mPrev;
  }
  this->mAvoidable.m_pPointer = (UFG::SimComponent *)&pAvoidable->vfptr;
  if ( pAvoidable )
  {
    v8 = pAvoidable->m_SafePointerList.mNode.mPrev;
    v8->mNext = v5;
    v5->mPrev = v8;
    this->mAvoidable.mNext = &pAvoidable->m_SafePointerList.mNode;
    pAvoidable->m_SafePointerList.mNode.mPrev = v5;
  }
  if ( pParent
    && (v9 = UFG::SimObject::GetComponentOfType(pParent, UFG::FlowfieldComponent::_TypeUID), (v11 = v9) != 0i64) )
  {
    if ( v3->mpFieldPrint.m_pPointer )
    {
      v12 = 0i64;
      LOBYTE(v10) = 1;
      ((void (__fastcall *)(UFG::SimComponent *, _QWORD, __int64))v9->vfptr[19].__vecDelDtor)(v9, 0i64, v10);
      v4->mbDeleteFieldPrint = 1;
    }
    else
    {
      v13 = UFG::qMalloc(0xE8ui64, "FFieldAvoidablePrint", 0i64);
      if ( v13 )
      {
        UFG::FFieldAvoidablePrint::FFieldAvoidablePrint((UFG::FFieldAvoidablePrint *)v13, v3, 1, 1.0);
        v12 = v15;
      }
      else
      {
        v12 = 0i64;
      }
      LOBYTE(v14) = 1;
      ((void (__fastcall *)(UFG::SimComponent *, UFG::FlowfieldPrint *, __int64))v11->vfptr[19].__vecDelDtor)(
        v11,
        v12,
        v14);
      v4->mbDeleteFieldPrint = 1;
      v12->m_Enabled = ~(v3->mFlags >> 9) & 1;
    }
    v16 = &v4->mFieldPrint;
    if ( v4->mFieldPrint.m_pPointer )
    {
      v17 = v16->mPrev;
      v18 = v4->mFieldPrint.mNext;
      v17->mNext = v18;
      v18->mPrev = v17;
      v16->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *)&v16->mPrev;
      v4->mFieldPrint.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *)&v4->mFieldPrint.mPrev;
    }
    v4->mFieldPrint.m_pPointer = v12;
    if ( v12 )
    {
      v19 = v12->m_SafePointerList.mNode.mPrev;
      v19->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *)&v16->mPrev;
      v16->mPrev = v19;
      v4->mFieldPrint.mNext = &v12->m_SafePointerList.mNode;
      v12->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *)&v16->mPrev;
    }
  }
  else
  {
    v20 = &v4->mFieldPrint;
    if ( v4->mFieldPrint.m_pPointer )
    {
      v21 = v20->mPrev;
      v22 = v4->mFieldPrint.mNext;
      v21->mNext = v22;
      v22->mPrev = v21;
      v20->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *)&v20->mPrev;
      v4->mFieldPrint.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *)&v4->mFieldPrint.mPrev;
    }
    v4->mFieldPrint.m_pPointer = 0i64;
  }
}

// File Line: 141
// RVA: 0x14613A0
__int64 dynamic_initializer_for__UFG::AvoidanceController::s_AvoidanceControllerList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::AvoidanceController::s_AvoidanceControllerList__);
}

// File Line: 142
// RVA: 0xFFED0
signed __int64 __fastcall UFG::VehicleSpot::GetTypeSize(UFG::AvoidanceController *this)
{
  return 192i64;
}

// File Line: 153
// RVA: 0xFA910
void __fastcall UFG::AvoidanceController::AvoidanceController(UFG::AvoidanceController *this, unsigned int name_uid)
{
  UFG::AvoidanceController *v2; // rsi
  UFG::qNode<UFG::AvoidanceController,UFG::AvoidanceController> *v3; // rdi
  UFG::qNode<UFG::AvoidanceController,UFG::AvoidanceController> *v4; // rax
  signed __int64 v5; // rdx
  UFG::qSafePointer<UFG::SimComponent,UFG::AIInterestComponent> *v6; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::qSafePointer<UFG::FlowfieldPrint,UFG::FlowfieldPrint> *v9; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AIInterestComponent> *v12; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qSafePointer<UFG::FlowfieldPrint,UFG::FlowfieldPrint> *v15; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *v16; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *v17; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AIInterestComponent> *v18; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v20; // rax
  UFG::qSafePointer<UFG::FlowfieldPrint,UFG::FlowfieldPrint> *v21; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *v22; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *v23; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AIInterestComponent> *v24; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v25; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v26; // rax
  UFG::qSafePointer<UFG::FlowfieldPrint,UFG::FlowfieldPrint> *v27; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *v28; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *v29; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AIInterestComponent> *v30; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v31; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v32; // rax
  UFG::qSafePointer<UFG::FlowfieldPrint,UFG::FlowfieldPrint> *v33; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *v34; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *v35; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AIInterestComponent> *v36; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v37; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v38; // rax
  UFG::qSafePointer<UFG::FlowfieldPrint,UFG::FlowfieldPrint> *v39; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *v40; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *v41; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AIInterestComponent> *v42; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v43; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v44; // rax
  UFG::qSafePointer<UFG::FlowfieldPrint,UFG::FlowfieldPrint> *v45; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *v46; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *v47; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AIInterestComponent> *v48; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v49; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v50; // rax
  UFG::qSafePointer<UFG::FlowfieldPrint,UFG::FlowfieldPrint> *v51; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *v52; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *v53; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v54; // [rsp+60h] [rbp+18h]

  v2 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, name_uid);
  v2->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::StateComponentI<UFG::SimComponent>::`vftable{for `UFG::SimComponent};
  v2->vfptr = (UFG::StateInterfaceVtbl *)&UFG::StateComponentI<UFG::SimComponent>::`vftable{for `UFG::StateInterface};
  v2->mAutoActivate = 1;
  v2->mAge = 0.0;
  v3 = (UFG::qNode<UFG::AvoidanceController,UFG::AvoidanceController> *)&v2->mPrev;
  v3->mPrev = v3;
  v3->mNext = v3;
  v2->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AvoidanceController::`vftable{for `UFG::SimComponent};
  v2->vfptr = (UFG::StateInterfaceVtbl *)&UFG::AvoidanceController::`vftable{for `UFG::StateInterface};
  v2->mParams.MaxUpdateTimePerFrame = 0.0024999999;
  v2->mParams.MMFrontDP.x = -0.1;
  v2->mParams.MMFrontDP.y = 0.80000001;
  v2->mParams.MMLateralVel = (UFG::qVector2)0x40000000i64;
  v2->mParams.MMDistance.x = 10.0;
  v2->mParams.MMDistance.y = 2.0;
  v2->mParams.MMLateralDist.x = 15.0;
  v2->mParams.MMLateralDist.y = 3.0;
  v2->mParams.MMSecondsToImpact.x = 2.0;
  v2->mParams.MMSecondsToImpact.y = 0.2;
  v2->mActiveAvoidPairs.p = 0i64;
  *(_QWORD *)&v2->mActiveAvoidPairs.size = 0i64;
  UFG::qArray<UFG::AvoidPairInstance,0>::Reallocate(&v2->mActiveAvoidPairs, 0x20u, "qArray.Reallocate(Constructor)");
  v2->mActiveAvoidPairs.size = 32;
  v2->mNumActivePairs = 0;
  v54 = &v2->mpTransform;
  v54->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v54->mPrev;
  v54->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v54->mPrev;
  v2->mpTransform.m_pPointer = 0i64;
  v4 = UFG::AvoidanceController::s_AvoidanceControllerList.mNode.mPrev;
  UFG::AvoidanceController::s_AvoidanceControllerList.mNode.mPrev->mNext = (UFG::qNode<UFG::AvoidanceController,UFG::AvoidanceController> *)&v2->mPrev;
  v3->mPrev = v4;
  v2->mNext = (UFG::qNode<UFG::AvoidanceController,UFG::AvoidanceController> *)&UFG::AvoidanceController::s_AvoidanceControllerList;
  UFG::AvoidanceController::s_AvoidanceControllerList.mNode.mPrev = (UFG::qNode<UFG::AvoidanceController,UFG::AvoidanceController> *)&v2->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v2->vfptr,
    UFG::AvoidanceController::_AvoidanceControllerTypeUID,
    "AvoidanceController");
  v5 = 0i64;
  do
  {
    v2->mActiveAvoidPairs.p[v5].mbDeleteFieldPrint = 0;
    v2->mActiveAvoidPairs.p[v5].mAge = 0.0;
    v2->mActiveAvoidPairs.p[v5].mScore = 0.0;
    v6 = &v2->mActiveAvoidPairs.p[v5].mAvoidable;
    if ( v6->m_pPointer )
    {
      v7 = v6->mPrev;
      v8 = v6->mNext;
      v7->mNext = v8;
      v8->mPrev = v7;
      v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
      v6->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
    }
    v6->m_pPointer = 0i64;
    v9 = &v2->mActiveAvoidPairs.p[v5].mFieldPrint;
    if ( v9->m_pPointer )
    {
      v10 = v9->mPrev;
      v11 = v9->mNext;
      v10->mNext = v11;
      v11->mPrev = v10;
      v9->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *)&v9->mPrev;
      v9->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *)&v9->mPrev;
    }
    v9->m_pPointer = 0i64;
    v2->mActiveAvoidPairs.p[v5 + 1].mbDeleteFieldPrint = 0;
    v2->mActiveAvoidPairs.p[v5 + 1].mAge = 0.0;
    v2->mActiveAvoidPairs.p[v5 + 1].mScore = 0.0;
    v12 = &v2->mActiveAvoidPairs.p[v5 + 1].mAvoidable;
    if ( v12->m_pPointer )
    {
      v13 = v12->mPrev;
      v14 = v12->mNext;
      v13->mNext = v14;
      v14->mPrev = v13;
      v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v12->mPrev;
      v12->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v12->mPrev;
    }
    v12->m_pPointer = 0i64;
    v15 = &v2->mActiveAvoidPairs.p[v5 + 1].mFieldPrint;
    if ( v15->m_pPointer )
    {
      v16 = v15->mPrev;
      v17 = v15->mNext;
      v16->mNext = v17;
      v17->mPrev = v16;
      v15->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *)&v15->mPrev;
      v15->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *)&v15->mPrev;
    }
    v15->m_pPointer = 0i64;
    v2->mActiveAvoidPairs.p[v5 + 2].mbDeleteFieldPrint = 0;
    v2->mActiveAvoidPairs.p[v5 + 2].mAge = 0.0;
    v2->mActiveAvoidPairs.p[v5 + 2].mScore = 0.0;
    v18 = &v2->mActiveAvoidPairs.p[v5 + 2].mAvoidable;
    if ( v18->m_pPointer )
    {
      v19 = v18->mPrev;
      v20 = v18->mNext;
      v19->mNext = v20;
      v20->mPrev = v19;
      v18->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v18->mPrev;
      v18->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v18->mPrev;
    }
    v18->m_pPointer = 0i64;
    v21 = &v2->mActiveAvoidPairs.p[v5 + 2].mFieldPrint;
    if ( v21->m_pPointer )
    {
      v22 = v21->mPrev;
      v23 = v21->mNext;
      v22->mNext = v23;
      v23->mPrev = v22;
      v21->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *)&v21->mPrev;
      v21->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *)&v21->mPrev;
    }
    v21->m_pPointer = 0i64;
    v2->mActiveAvoidPairs.p[v5 + 3].mbDeleteFieldPrint = 0;
    v2->mActiveAvoidPairs.p[v5 + 3].mAge = 0.0;
    v2->mActiveAvoidPairs.p[v5 + 3].mScore = 0.0;
    v24 = &v2->mActiveAvoidPairs.p[v5 + 3].mAvoidable;
    if ( v24->m_pPointer )
    {
      v25 = v24->mPrev;
      v26 = v24->mNext;
      v25->mNext = v26;
      v26->mPrev = v25;
      v24->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v24->mPrev;
      v24->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v24->mPrev;
    }
    v24->m_pPointer = 0i64;
    v27 = &v2->mActiveAvoidPairs.p[v5 + 3].mFieldPrint;
    if ( v27->m_pPointer )
    {
      v28 = v27->mPrev;
      v29 = v27->mNext;
      v28->mNext = v29;
      v29->mPrev = v28;
      v27->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *)&v27->mPrev;
      v27->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *)&v27->mPrev;
    }
    v27->m_pPointer = 0i64;
    v2->mActiveAvoidPairs.p[v5 + 4].mbDeleteFieldPrint = 0;
    v2->mActiveAvoidPairs.p[v5 + 4].mAge = 0.0;
    v2->mActiveAvoidPairs.p[v5 + 4].mScore = 0.0;
    v30 = &v2->mActiveAvoidPairs.p[v5 + 4].mAvoidable;
    if ( v30->m_pPointer )
    {
      v31 = v30->mPrev;
      v32 = v30->mNext;
      v31->mNext = v32;
      v32->mPrev = v31;
      v30->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v30->mPrev;
      v30->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v30->mPrev;
    }
    v30->m_pPointer = 0i64;
    v33 = &v2->mActiveAvoidPairs.p[v5 + 4].mFieldPrint;
    if ( v33->m_pPointer )
    {
      v34 = v33->mPrev;
      v35 = v33->mNext;
      v34->mNext = v35;
      v35->mPrev = v34;
      v33->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *)&v33->mPrev;
      v33->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *)&v33->mPrev;
    }
    v33->m_pPointer = 0i64;
    v2->mActiveAvoidPairs.p[v5 + 5].mbDeleteFieldPrint = 0;
    v2->mActiveAvoidPairs.p[v5 + 5].mAge = 0.0;
    v2->mActiveAvoidPairs.p[v5 + 5].mScore = 0.0;
    v36 = &v2->mActiveAvoidPairs.p[v5 + 5].mAvoidable;
    if ( v36->m_pPointer )
    {
      v37 = v36->mPrev;
      v38 = v36->mNext;
      v37->mNext = v38;
      v38->mPrev = v37;
      v36->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v36->mPrev;
      v36->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v36->mPrev;
    }
    v36->m_pPointer = 0i64;
    v39 = &v2->mActiveAvoidPairs.p[v5 + 5].mFieldPrint;
    if ( v39->m_pPointer )
    {
      v40 = v39->mPrev;
      v41 = v39->mNext;
      v40->mNext = v41;
      v41->mPrev = v40;
      v39->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *)&v39->mPrev;
      v39->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *)&v39->mPrev;
    }
    v39->m_pPointer = 0i64;
    v2->mActiveAvoidPairs.p[v5 + 6].mbDeleteFieldPrint = 0;
    v2->mActiveAvoidPairs.p[v5 + 6].mAge = 0.0;
    v2->mActiveAvoidPairs.p[v5 + 6].mScore = 0.0;
    v42 = &v2->mActiveAvoidPairs.p[v5 + 6].mAvoidable;
    if ( v42->m_pPointer )
    {
      v43 = v42->mPrev;
      v44 = v42->mNext;
      v43->mNext = v44;
      v44->mPrev = v43;
      v42->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v42->mPrev;
      v42->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v42->mPrev;
    }
    v42->m_pPointer = 0i64;
    v45 = &v2->mActiveAvoidPairs.p[v5 + 6].mFieldPrint;
    if ( v45->m_pPointer )
    {
      v46 = v45->mPrev;
      v47 = v45->mNext;
      v46->mNext = v47;
      v47->mPrev = v46;
      v45->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *)&v45->mPrev;
      v45->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *)&v45->mPrev;
    }
    v45->m_pPointer = 0i64;
    v2->mActiveAvoidPairs.p[v5 + 7].mbDeleteFieldPrint = 0;
    v2->mActiveAvoidPairs.p[v5 + 7].mAge = 0.0;
    v2->mActiveAvoidPairs.p[v5 + 7].mScore = 0.0;
    v48 = &v2->mActiveAvoidPairs.p[v5 + 7].mAvoidable;
    if ( v48->m_pPointer )
    {
      v49 = v48->mPrev;
      v50 = v48->mNext;
      v49->mNext = v50;
      v50->mPrev = v49;
      v48->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v48->mPrev;
      v48->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v48->mPrev;
    }
    v48->m_pPointer = 0i64;
    v51 = &v2->mActiveAvoidPairs.p[v5 + 7].mFieldPrint;
    if ( v51->m_pPointer )
    {
      v52 = v51->mPrev;
      v53 = v51->mNext;
      v52->mNext = v53;
      v53->mPrev = v52;
      v51->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *)&v51->mPrev;
      v51->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *)&v51->mPrev;
    }
    v51->m_pPointer = 0i64;
    v5 += 8i64;
  }
  while ( v5 < 32 );
}

// File Line: 171
// RVA: 0xFBAF0
void __fastcall UFG::AvoidanceController::~AvoidanceController(UFG::AvoidanceController *this)
{
  UFG::AvoidanceController *v1; // rdi
  UFG::qNode<UFG::AvoidanceController,UFG::AvoidanceController> *v2; // rsi
  UFG::qNode<UFG::AvoidanceController,UFG::AvoidanceController> *v3; // rcx
  UFG::qNode<UFG::AvoidanceController,UFG::AvoidanceController> *v4; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v5; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::AvoidPairInstance *v10; // rcx
  UFG::SimComponent **v11; // rbx
  UFG::qNode<UFG::AvoidanceController,UFG::AvoidanceController> *v12; // rcx
  UFG::qNode<UFG::AvoidanceController,UFG::AvoidanceController> *v13; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AvoidanceController::`vftable{for `UFG::SimComponent};
  this->vfptr = (UFG::StateInterfaceVtbl *)&UFG::AvoidanceController::`vftable{for `UFG::StateInterface};
  if ( this == UFG::AvoidanceController::s_AvoidanceControllerpCurrentIterator )
    UFG::AvoidanceController::s_AvoidanceControllerpCurrentIterator = (UFG::AvoidanceController *)&this->mPrev[-5];
  v2 = (UFG::qNode<UFG::AvoidanceController,UFG::AvoidanceController> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  v5 = &v1->mpTransform;
  if ( v1->mpTransform.m_pPointer )
  {
    v6 = v5->mPrev;
    v7 = v1->mpTransform.mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
    v1->mpTransform.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mpTransform.mPrev;
  }
  v1->mpTransform.m_pPointer = 0i64;
  v8 = v5->mPrev;
  v9 = v1->mpTransform.mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  v1->mpTransform.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mpTransform.mPrev;
  v10 = v1->mActiveAvoidPairs.p;
  if ( v10 )
  {
    v11 = &v10[-1].mAvoidable.m_pPointer;
    `eh vector destructor iterator(
      v10,
      0x40ui64,
      (int)v10[-1].mAvoidable.m_pPointer,
      (void (__fastcall *)(void *))UFG::AvoidPairInstance::~AvoidPairInstance);
    operator delete[](v11);
  }
  v1->mActiveAvoidPairs.p = 0i64;
  *(_QWORD *)&v1->mActiveAvoidPairs.size = 0i64;
  v12 = v2->mPrev;
  v13 = v2->mNext;
  v12->mNext = v13;
  v13->mPrev = v12;
  v2->mPrev = v2;
  v2->mNext = v2;
  v1->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::StateComponentI<UFG::SimComponent>::`vftable{for `UFG::SimComponent};
  v1->vfptr = (UFG::StateInterfaceVtbl *)&UFG::StateComponentI<UFG::SimComponent>::`vftable{for `UFG::StateInterface};
  if ( (LOBYTE(v1->m_Flags) >> 2) & 1 )
  {
    v1->m_Flags |= 2u;
    ((void (__fastcall *)(UFG::AvoidanceController *))v1->vfptr[16].__vecDelDtor)(v1);
    v1->m_Flags &= 0xFFFBu;
  }
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 179
// RVA: 0x100950
void __fastcall UFG::AvoidanceController::OnAttach(UFG::AvoidanceController *this, UFG::SimObject *object)
{
  UFG::TransformNodeComponent *v2; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v3; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax

  if ( object )
    v2 = object->m_pTransformNodeComponent;
  else
    v2 = 0i64;
  v3 = &this->mpTransform;
  if ( this->mpTransform.m_pPointer )
  {
    v4 = v3->mPrev;
    v5 = v3->mNext;
    v4->mNext = v5;
    v5->mPrev = v4;
    v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
    v3->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  }
  v3->m_pPointer = (UFG::SimComponent *)&v2->vfptr;
  if ( v2 )
  {
    v6 = v2->m_SafePointerList.mNode.mPrev;
    v6->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
    v3->mPrev = v6;
    v3->mNext = &v2->m_SafePointerList.mNode;
    v2->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  }
}

// File Line: 188
// RVA: 0x101200
void __fastcall UFG::AvoidanceController::OnDetach(UFG::AvoidanceController *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v1; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v2; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rax

  v1 = &this->mpTransform;
  if ( this->mpTransform.m_pPointer )
  {
    v2 = v1->mPrev;
    v3 = v1->mNext;
    v2->mNext = v3;
    v3->mPrev = v2;
    v1->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mPrev;
    v1->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mPrev;
  }
  v1->m_pPointer = 0i64;
}

// File Line: 197
// RVA: 0x1012F0
void __fastcall UFG::AvoidanceController::OnReset(UFG::AvoidanceController *this)
{
  UFG::AvoidanceController *v1; // rsi
  signed __int64 v2; // rbx
  UFG::AvoidPairInstance *v3; // rdi
  UFG::FlowfieldPrint *v4; // rcx
  UFG::FlowfieldPrint *v5; // rax
  UFG::qSafePointer<UFG::FlowfieldPrint,UFG::FlowfieldPrint> *v6; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AIInterestComponent> *v9; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax

  v1 = this;
  this->mNumActivePairs = 0;
  v2 = 0i64;
  do
  {
    v3 = v1->mActiveAvoidPairs.p;
    if ( v3[v2].mbDeleteFieldPrint && (v4 = v3[v2].mFieldPrint.m_pPointer) != 0i64 )
    {
      v4->vfptr->__vecDelDtor((UFG::qSafePointerNode<UFG::FlowfieldPrint> *)&v4->vfptr, 1u);
    }
    else
    {
      v5 = v3[v2].mFieldPrint.m_pPointer;
      if ( v5 )
        v5->m_Enabled = 0;
    }
    v6 = &v3[v2].mFieldPrint;
    if ( v6->m_pPointer )
    {
      v7 = v6->mPrev;
      v8 = v6->mNext;
      v7->mNext = v8;
      v8->mPrev = v7;
      v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *)&v6->mPrev;
      v6->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *)&v6->mPrev;
    }
    v6->m_pPointer = 0i64;
    v9 = &v3[v2].mAvoidable;
    if ( v9->m_pPointer )
    {
      v10 = v9->mPrev;
      v11 = v9->mNext;
      v10->mNext = v11;
      v11->mPrev = v10;
      v9->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
      v9->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
    }
    v9->m_pPointer = 0i64;
    v3[v2].mbDeleteFieldPrint = 0;
    *(_QWORD *)&v3[v2].mScore = 0i64;
    ++v2;
  }
  while ( v2 < 32 );
}

// File Line: 210
// RVA: 0x101930
void __fastcall UFG::AvoidanceController::OnUpdate(UFG::AvoidanceController *this, float fDeltaT)
{
  signed __int64 v2; // rsi
  UFG::AvoidanceController *v3; // rdi
  float v4; // xmm7_4
  float v5; // xmm0_4
  UFG::AvoidPairInstance *v6; // rbx
  float v7; // xmm0_4
  UFG::AIInterestComponent *v8; // rdx
  float v9; // xmm0_4
  float v10; // xmm1_4

  v2 = 0i64;
  v3 = this;
  this->mOverallAvoidScore = 0.0;
  v4 = fDeltaT;
  v5 = UFG::AvoidanceController::AddCloseAvoidables_ALL(this);
  if ( v5 >= v3->mOverallAvoidScore )
    v5 = v3->mOverallAvoidScore;
  v3->mOverallAvoidScore = v5;
  do
  {
    v6 = &v3->mActiveAvoidPairs.p[v2];
    v7 = v6->mAge;
    if ( v7 > 0.0 )
    {
      v8 = (UFG::AIInterestComponent *)v6->mAvoidable.m_pPointer;
      if ( v8
        && (v7 != 0.000099999997 ? (v9 = UFG::AvoidanceController::ShouldAvoid(v3, v8), v6->mScore = v9) : (v9 = v6->mScore),
            v6->mAge = v4 + v6->mAge,
            v9 != 0.0) )
      {
        v10 = v3->mOverallAvoidScore;
        if ( v10 <= v9 )
          v10 = v9;
        v3->mOverallAvoidScore = v10;
      }
      else
      {
        UFG::AvoidPairInstance::Clear(v6);
        --v3->mNumActivePairs;
      }
    }
    ++v2;
  }
  while ( v2 < 32 );
}

// File Line: 241
// RVA: 0xFC8D0
float __fastcall UFG::AvoidanceController::AddCloseAvoidables_ALL(UFG::AvoidanceController *this)
{
  UFG::AIInterestComponent *v1; // rbx
  UFG::AvoidanceController *v2; // rdi
  float i; // xmm6_4
  float v4; // xmm0_4

  v1 = (UFG::AIInterestComponent *)&UFG::AIInterestComponent::s_AIInterestComponentList.mNode.mNext[-5];
  v2 = this;
  for ( i = 0.0;
        v1 != (UFG::AIInterestComponent *)(&UFG::AIInterestComponent::s_AIInterestComponentList - 5);
        v1 = (UFG::AIInterestComponent *)&v1->mNext[-5] )
  {
    if ( v1->m_pSimObject != v2->m_pSimObject )
    {
      v4 = UFG::AvoidanceController::AddCloseAvoidable(v2, v1);
      if ( i <= v4 )
        i = v4;
      if ( v2->mNumActivePairs == 32 )
        break;
    }
  }
  return i;
}

// File Line: 263
// RVA: 0x102470
float __fastcall UFG::AvoidanceController::ShouldAvoid(UFG::AvoidanceController *this, UFG::AIInterestComponent *pAvoidable)
{
  UFG::AIInterestComponent *v2; // rsi
  UFG::AvoidanceController *v3; // rdi
  UFG::SimComponent *v4; // rbp
  float v5; // xmm6_4
  float *v6; // rbx
  float v7; // xmm12_4
  __m128 v8; // xmm10
  float v9; // xmm13_4
  __m128 v10; // xmm2
  float v11; // xmm1_4
  float v12; // xmm7_4
  float v13; // xmm9_4
  UFG::SimComponent *v14; // rbx
  float v15; // xmm3_4
  __m128 v16; // xmm4
  float v17; // xmm5_4
  __m128 v18; // xmm2
  float v19; // xmm1_4
  float v20; // xmm3_4
  float v21; // xmm4_4
  float v22; // xmm5_4
  float *v23; // rbx
  float v24; // xmm7_4
  float v25; // xmm1_4
  float v26; // xmm7_4
  float *v27; // rbx
  float v28; // xmm1_4
  float v29; // xmm2_4
  UFG::SimComponent *v30; // rbx
  UFG::TransformNodeComponent *v31; // rcx
  float v32; // xmm1_4
  float v33; // xmm0_4
  float v34; // xmm0_4
  float v35; // xmm2_4
  float v36; // xmm1_4
  __m128 v37; // xmm3
  float v38; // xmm11_4
  float *v39; // rbx
  float v40; // xmm10_4
  UFG::qVector3 v1; // [rsp+30h] [rbp-B8h]
  UFG::qVector3 v0; // [rsp+40h] [rbp-A8h]
  UFG::qVector3 result; // [rsp+50h] [rbp-98h]

  v2 = pAvoidable;
  v3 = this;
  if ( pAvoidable && pAvoidable->mFlags & 1 && (LOBYTE(pAvoidable->mFlags) >> 4) & 1 )
  {
    v4 = pAvoidable->mpTransform.m_pPointer;
    v5 = 0.0;
    UFG::AIInterestComponent::GetCenter(pAvoidable, &result, 0.0);
    v6 = (float *)v3->mpTransform.m_pPointer;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v3->mpTransform.m_pPointer);
    v8 = (__m128)LODWORD(result.y);
    v7 = result.x - v6[44];
    v8.m128_f32[0] = result.y - v6[45];
    v9 = result.z - v6[46];
    v10 = v8;
    v10.m128_f32[0] = (float)((float)(v8.m128_f32[0] * v8.m128_f32[0]) + (float)(v7 * v7)) + (float)(v9 * v9);
    v11 = v3->mParams.MMDistance.x;
    LODWORD(v12) = (unsigned __int128)_mm_sqrt_ps(v10);
    if ( v12 >= v11 )
      return v5;
    v13 = (float)(v12 - v11) / (float)(v3->mParams.MMDistance.y - v11);
    if ( v13 <= 0.0 )
    {
      v13 = 0.0;
    }
    else if ( v13 >= 1.0 )
    {
      v13 = *(float *)&FLOAT_1_0;
    }
    v14 = v3->mpTransform.m_pPointer;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v3->mpTransform.m_pPointer);
    v15 = *(float *)&v14[4].vfptr;
    v16 = (__m128)HIDWORD(v14[4].vfptr);
    v17 = *(float *)&v14[4].m_SafePointerList.mNode.mPrev;
    v18 = v16;
    v18.m128_f32[0] = (float)((float)(v16.m128_f32[0] * v16.m128_f32[0]) + (float)(v15 * v15)) + (float)(v17 * v17);
    LODWORD(v19) = (unsigned __int128)_mm_sqrt_ps(v18);
    if ( v19 <= 15.0 )
    {
      v23 = (float *)v3->mpTransform.m_pPointer;
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v3->mpTransform.m_pPointer);
      v20 = v23[32];
      v21 = v23[33];
      v22 = v23[34];
    }
    else
    {
      v20 = v15 * (float)(1.0 / v19);
      v21 = v16.m128_f32[0] * (float)(1.0 / v19);
      v22 = v17 * (float)(1.0 / v19);
    }
    v24 = (float)((float)((float)((float)(1.0 / v12) * v8.m128_f32[0]) * v21)
                + (float)((float)((float)(1.0 / v12) * v7) * v20))
        + (float)((float)((float)(1.0 / v12) * v9) * v22);
    v25 = v3->mParams.MMFrontDP.x;
    if ( v24 <= v25 )
      return v5;
    v26 = (float)(v24 - v25) / (float)(v3->mParams.MMFrontDP.y - v25);
    if ( v26 <= 0.0 )
    {
      v26 = 0.0;
    }
    else if ( v26 >= 1.0 )
    {
      v26 = *(float *)&FLOAT_1_0;
    }
    if ( v2->mFlags & 0x100 )
    {
      if ( v26 >= v13 )
        return v13;
    }
    else
    {
      v27 = (float *)v3->mpTransform.m_pPointer;
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v3->mpTransform.m_pPointer);
      v28 = v27[65];
      v29 = v27[66];
      v1.x = v27[64];
      v1.y = v28;
      v1.z = v29;
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v4);
      v30 = v3->mpTransform.m_pPointer;
      v31 = (UFG::TransformNodeComponent *)v3->mpTransform.m_pPointer;
      v32 = *((float *)&v4[4].vfptr + 1);
      v0.x = *(float *)&v4[4].vfptr;
      v33 = *(float *)&v4[4].m_SafePointerList.mNode.mPrev;
      v0.y = v32;
      v0.z = v33;
      UFG::TransformNodeComponent::UpdateWorldTransform(v31);
      v34 = UFG::ClosingTime(&result, &v0, (UFG::qVector3 *)&v30[2].m_BoundComponentHandles, &v1, 0i64);
      v35 = v3->mParams.MMSecondsToImpact.x;
      if ( v34 >= v35 )
      {
        v37 = (__m128)LODWORD(v1.y);
        v37.m128_f32[0] = (float)((float)((float)(v1.y - v0.y) * (float)(v1.y - v0.y))
                                + (float)((float)(v1.x - v0.x) * (float)(v1.x - v0.x)))
                        + (float)((float)(v1.z - v0.z) * (float)(v1.z - v0.z));
        v38 = (float)(COERCE_FLOAT(_mm_sqrt_ps(v37)) - v3->mParams.MMLateralVel.x)
            / (float)(v3->mParams.MMLateralVel.y - v3->mParams.MMLateralVel.x);
        if ( v38 <= 0.0 )
        {
          v38 = 0.0;
        }
        else if ( v38 >= 1.0 )
        {
          v38 = *(float *)&FLOAT_1_0;
        }
        v39 = (float *)v3->mpTransform.m_pPointer;
        UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v3->mpTransform.m_pPointer);
        v40 = (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(
                                     (float)((float)(v8.m128_f32[0] * v39[37]) + (float)(v7 * v39[36]))
                                   + (float)(v9 * v39[38])) & _xmm)
                    - v3->mParams.MMLateralDist.x)
            / (float)(v3->mParams.MMLateralDist.y - v3->mParams.MMLateralDist.x);
        if ( v40 > 0.0 )
        {
          v5 = v40;
          if ( v40 >= 1.0 )
            v5 = *(float *)&FLOAT_1_0;
        }
        v5 = v5 * v38;
      }
      else
      {
        v36 = (float)(v34 - v35) / (float)(v3->mParams.MMSecondsToImpact.y - v35);
        if ( v36 > 0.0 )
        {
          v5 = (float)(v34 - v35) / (float)(v3->mParams.MMSecondsToImpact.y - v35);
          if ( v36 >= 1.0 )
            v5 = *(float *)&FLOAT_1_0;
        }
      }
      if ( v26 >= v13 )
        v26 = v13;
      if ( v5 < v26 )
        return v5;
    }
    return v26;
  }
  return 0.0;
}

// File Line: 422
// RVA: 0xFC7A0
float __fastcall UFG::AvoidanceController::AddCloseAvoidable(UFG::AvoidanceController *this, UFG::AIInterestComponent *pAvoidable)
{
  unsigned int v2; // ebx
  UFG::AIInterestComponent *v3; // rsi
  UFG::AvoidanceController *v4; // rdi
  UFG::AIInterestComponent **v5; // rax
  signed __int64 v6; // r8
  float result; // xmm0_4
  signed __int64 v8; // rcx
  UFG::AvoidPairInstance *v9; // rdx
  float *v10; // rax
  unsigned __int64 v11; // rbx
  float *v12; // rax

  v2 = 0;
  v3 = pAvoidable;
  v4 = this;
  v5 = (UFG::AIInterestComponent **)&this->mActiveAvoidPairs.p->mAvoidable.m_pPointer;
  v6 = 0i64;
  do
  {
    if ( *((float *)v5 - 13) > 0.0 && pAvoidable == *v5 )
      return 0.0;
    ++v6;
    v5 += 8;
  }
  while ( v6 < 32 );
  result = UFG::AvoidanceController::ShouldAvoid(this, pAvoidable);
  if ( result > 0.0 )
  {
    v8 = 0i64;
    if ( v4->mNumActivePairs == 32 )
    {
      v9 = v4->mActiveAvoidPairs.p;
      v10 = &v4->mActiveAvoidPairs.p->mScore;
      while ( (float)(result * 0.75) <= *v10 )
      {
        ++v8;
        ++v2;
        v10 += 16;
        if ( v8 >= 32 )
          goto LABEL_10;
      }
      v4->mNumActivePairs = 31;
      UFG::AvoidPairInstance::Clear(&v9[(unsigned __int64)v2]);
    }
    else
    {
      v12 = &v4->mActiveAvoidPairs.p->mAge;
      while ( *v12 > 0.0 )
      {
        ++v8;
        ++v2;
        v12 += 16;
        if ( v8 >= 32 )
          return 0.0;
      }
    }
    if ( (v2 & 0x80000000) != 0 )
    {
LABEL_10:
      result = 0.0;
    }
    else
    {
      v11 = (unsigned __int64)v2 << 6;
      UFG::AvoidPairInstance::Init(
        (UFG::AvoidPairInstance *)((char *)v4->mActiveAvoidPairs.p + v11),
        v4->m_pSimObject,
        v3);
      *(float *)((char *)&v4->mActiveAvoidPairs.p->mScore + v11) = result;
      ++v4->mNumActivePairs;
    }
  }
  return result;
}

