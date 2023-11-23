// File Line: 36
// RVA: 0xFA880
void __fastcall UFG::AvoidPairInstance::AvoidPairInstance(UFG::AvoidPairInstance *this)
{
  UFG::qSafePointer<UFG::FlowfieldPrint,UFG::FlowfieldPrint> *p_mFieldPrint; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::AIInterestComponent> *p_mAvoidable; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax

  p_mFieldPrint = &this->mFieldPrint;
  this->mFieldPrint.mPrev = &this->mFieldPrint;
  this->mFieldPrint.mNext = &this->mFieldPrint;
  this->mFieldPrint.m_pPointer = 0i64;
  p_mAvoidable = &this->mAvoidable;
  this->mAvoidable.mPrev = &this->mAvoidable;
  this->mAvoidable.mNext = &this->mAvoidable;
  this->mAvoidable.m_pPointer = 0i64;
  if ( this->mFieldPrint.m_pPointer )
  {
    mPrev = p_mFieldPrint->mPrev;
    mNext = p_mFieldPrint->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mFieldPrint->mPrev = p_mFieldPrint;
    p_mFieldPrint->mNext = p_mFieldPrint;
  }
  p_mFieldPrint->m_pPointer = 0i64;
  if ( p_mAvoidable->m_pPointer )
  {
    v6 = p_mAvoidable->mPrev;
    v7 = p_mAvoidable->mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    p_mAvoidable->mPrev = p_mAvoidable;
    p_mAvoidable->mNext = p_mAvoidable;
  }
  p_mAvoidable->m_pPointer = 0i64;
  this->mbDeleteFieldPrint = 0;
  *(_QWORD *)&this->mScore = 0i64;
}

// File Line: 55
// RVA: 0xFBA50
void __fastcall UFG::AvoidPairInstance::~AvoidPairInstance(UFG::AvoidPairInstance *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::AIInterestComponent> *p_mAvoidable; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::FlowfieldPrint,UFG::FlowfieldPrint> *p_mFieldPrint; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *v11; // rax

  UFG::AvoidPairInstance::Clear(this);
  p_mAvoidable = &this->mAvoidable;
  if ( this->mAvoidable.m_pPointer )
  {
    mPrev = p_mAvoidable->mPrev;
    mNext = this->mAvoidable.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mAvoidable->mPrev = p_mAvoidable;
    this->mAvoidable.mNext = &this->mAvoidable;
  }
  this->mAvoidable.m_pPointer = 0i64;
  v5 = p_mAvoidable->mPrev;
  v6 = this->mAvoidable.mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_mAvoidable->mPrev = p_mAvoidable;
  this->mAvoidable.mNext = &this->mAvoidable;
  p_mFieldPrint = &this->mFieldPrint;
  if ( this->mFieldPrint.m_pPointer )
  {
    v8 = p_mFieldPrint->mPrev;
    v9 = this->mFieldPrint.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    p_mFieldPrint->mPrev = p_mFieldPrint;
    this->mFieldPrint.mNext = &this->mFieldPrint;
  }
  this->mFieldPrint.m_pPointer = 0i64;
  v10 = p_mFieldPrint->mPrev;
  v11 = this->mFieldPrint.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  p_mFieldPrint->mPrev = p_mFieldPrint;
  this->mFieldPrint.mNext = &this->mFieldPrint;
}

// File Line: 59
// RVA: 0xFCCF0
void __fastcall UFG::AvoidPairInstance::Clear(UFG::AvoidPairInstance *this)
{
  UFG::FlowfieldPrint *v2; // rcx
  UFG::FlowfieldPrint *m_pPointer; // rax
  UFG::qSafePointer<UFG::FlowfieldPrint,UFG::FlowfieldPrint> *p_mFieldPrint; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AIInterestComponent> *p_mAvoidable; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax

  if ( this->mbDeleteFieldPrint && (v2 = this->mFieldPrint.m_pPointer) != 0i64 )
  {
    v2->vfptr->__vecDelDtor(v2, 1u);
  }
  else
  {
    m_pPointer = this->mFieldPrint.m_pPointer;
    if ( m_pPointer )
      m_pPointer->m_Enabled = 0;
  }
  p_mFieldPrint = &this->mFieldPrint;
  if ( this->mFieldPrint.m_pPointer )
  {
    mPrev = p_mFieldPrint->mPrev;
    mNext = this->mFieldPrint.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mFieldPrint->mPrev = p_mFieldPrint;
    this->mFieldPrint.mNext = &this->mFieldPrint;
  }
  this->mFieldPrint.m_pPointer = 0i64;
  p_mAvoidable = &this->mAvoidable;
  if ( this->mAvoidable.m_pPointer )
  {
    v8 = p_mAvoidable->mPrev;
    v9 = this->mAvoidable.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    p_mAvoidable->mPrev = p_mAvoidable;
    this->mAvoidable.mNext = &this->mAvoidable;
  }
  this->mAvoidable.m_pPointer = 0i64;
  this->mbDeleteFieldPrint = 0;
  *(_QWORD *)&this->mScore = 0i64;
}

// File Line: 72
// RVA: 0x100240
void __fastcall UFG::AvoidPairInstance::Init(
        UFG::AvoidPairInstance *this,
        UFG::SimObject *pParent,
        UFG::AIInterestComponent *pAvoidable)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::AIInterestComponent> *p_mAvoidable; // r10
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::SimComponent *ComponentOfType; // rax
  __int64 v10; // r8
  UFG::SimComponent *v11; // r14
  UFG::FlowfieldPrint *v12; // rbx
  char *v13; // rax
  __int64 v14; // r8
  UFG::FlowfieldPrint *v15; // rax
  UFG::qSafePointer<UFG::FlowfieldPrint,UFG::FlowfieldPrint> *p_mFieldPrint; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *v17; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *v18; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::qSafePointer<UFG::FlowfieldPrint,UFG::FlowfieldPrint> *v20; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *v21; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *v22; // rax

  this->mAge = 0.000099999997;
  p_mAvoidable = &this->mAvoidable;
  if ( this->mAvoidable.m_pPointer )
  {
    mPrev = p_mAvoidable->mPrev;
    mNext = this->mAvoidable.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mAvoidable->mPrev = p_mAvoidable;
    this->mAvoidable.mNext = &this->mAvoidable;
  }
  this->mAvoidable.m_pPointer = pAvoidable;
  if ( pAvoidable )
  {
    v8 = pAvoidable->m_SafePointerList.mNode.UFG::StateComponentI<UFG::SimComponent>::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
    v8->mNext = p_mAvoidable;
    p_mAvoidable->mPrev = v8;
    this->mAvoidable.mNext = &pAvoidable->m_SafePointerList.mNode;
    pAvoidable->m_SafePointerList.mNode.UFG::StateComponentI<UFG::SimComponent>::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev = p_mAvoidable;
  }
  if ( pParent
    && (ComponentOfType = UFG::SimObject::GetComponentOfType(pParent, UFG::FlowfieldComponent::_TypeUID),
        (v11 = ComponentOfType) != 0i64) )
  {
    if ( pAvoidable->mpFieldPrint.m_pPointer )
    {
      v12 = 0i64;
      LOBYTE(v10) = 1;
      ((void (__fastcall *)(UFG::SimComponent *, _QWORD, __int64))ComponentOfType->vfptr[19].__vecDelDtor)(
        ComponentOfType,
        0i64,
        v10);
      this->mbDeleteFieldPrint = 1;
    }
    else
    {
      v13 = UFG::qMalloc(0xE8ui64, "FFieldAvoidablePrint", 0i64);
      if ( v13 )
      {
        UFG::FFieldAvoidablePrint::FFieldAvoidablePrint((UFG::FFieldAvoidablePrint *)v13, pAvoidable, 1, 1.0);
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
      this->mbDeleteFieldPrint = 1;
      v12->m_Enabled = (pAvoidable->mFlags & 0x200) == 0;
    }
    p_mFieldPrint = &this->mFieldPrint;
    if ( this->mFieldPrint.m_pPointer )
    {
      v17 = p_mFieldPrint->mPrev;
      v18 = this->mFieldPrint.mNext;
      v17->mNext = v18;
      v18->mPrev = v17;
      p_mFieldPrint->mPrev = p_mFieldPrint;
      this->mFieldPrint.mNext = &this->mFieldPrint;
    }
    this->mFieldPrint.m_pPointer = v12;
    if ( v12 )
    {
      v19 = v12->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::FlowfieldPrint>::mPrev;
      v19->mNext = p_mFieldPrint;
      p_mFieldPrint->mPrev = v19;
      this->mFieldPrint.mNext = &v12->m_SafePointerList.mNode;
      v12->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::FlowfieldPrint>::mPrev = p_mFieldPrint;
    }
  }
  else
  {
    v20 = &this->mFieldPrint;
    if ( this->mFieldPrint.m_pPointer )
    {
      v21 = v20->mPrev;
      v22 = this->mFieldPrint.mNext;
      v21->mNext = v22;
      v22->mPrev = v21;
      v20->mPrev = v20;
      this->mFieldPrint.mNext = &this->mFieldPrint;
    }
    this->mFieldPrint.m_pPointer = 0i64;
  }
}

// File Line: 141
// RVA: 0x14613A0
__int64 dynamic_initializer_for__UFG::AvoidanceController::s_AvoidanceControllerList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::AvoidanceController::s_AvoidanceControllerList__);
}

// File Line: 142
// RVA: 0xFFED0
__int64 __fastcall UFG::VehicleSpot::GetTypeSize(UFG::AvoidanceController *this)
{
  return 192i64;
}

// File Line: 153
// RVA: 0xFA910
void __fastcall UFG::AvoidanceController::AvoidanceController(UFG::AvoidanceController *this, unsigned int name_uid)
{
  UFG::qNode<UFG::AvoidanceController,UFG::AvoidanceController> *mPrev; // rax
  __int64 i; // rdx
  UFG::qSafePointer<UFG::SimComponent,UFG::AIInterestComponent> *p_mAvoidable; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qSafePointer<UFG::FlowfieldPrint,UFG::FlowfieldPrint> *p_mFieldPrint; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AIInterestComponent> *v11; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::qSafePointer<UFG::FlowfieldPrint,UFG::FlowfieldPrint> *v14; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AIInterestComponent> *v17; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::qSafePointer<UFG::FlowfieldPrint,UFG::FlowfieldPrint> *v20; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *v21; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *v22; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AIInterestComponent> *v23; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v24; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v25; // rax
  UFG::qSafePointer<UFG::FlowfieldPrint,UFG::FlowfieldPrint> *v26; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *v27; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *v28; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AIInterestComponent> *v29; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v30; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v31; // rax
  UFG::qSafePointer<UFG::FlowfieldPrint,UFG::FlowfieldPrint> *v32; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *v33; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *v34; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AIInterestComponent> *v35; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v36; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v37; // rax
  UFG::qSafePointer<UFG::FlowfieldPrint,UFG::FlowfieldPrint> *v38; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *v39; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *v40; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AIInterestComponent> *v41; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v42; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v43; // rax
  UFG::qSafePointer<UFG::FlowfieldPrint,UFG::FlowfieldPrint> *v44; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *v45; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *v46; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AIInterestComponent> *v47; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v48; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v49; // rax
  UFG::qSafePointer<UFG::FlowfieldPrint,UFG::FlowfieldPrint> *v50; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *v51; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *v52; // rax

  UFG::SimComponent::SimComponent(this, name_uid);
  this->UFG::StateComponentI<UFG::SimComponent>::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::StateComponentI<UFG::SimComponent>::`vftable{for `UFG::SimComponent};
  this->UFG::StateComponentI<UFG::SimComponent>::UFG::StateInterface::vfptr = (UFG::StateInterfaceVtbl *)&UFG::StateComponentI<UFG::SimComponent>::`vftable{for `UFG::StateInterface};
  this->mAutoActivate = 1;
  this->mAge = 0.0;
  this->mPrev = &this->UFG::qNode<UFG::AvoidanceController,UFG::AvoidanceController>;
  this->mNext = &this->UFG::qNode<UFG::AvoidanceController,UFG::AvoidanceController>;
  this->UFG::StateComponentI<UFG::SimComponent>::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AvoidanceController::`vftable{for `UFG::SimComponent};
  this->UFG::StateComponentI<UFG::SimComponent>::UFG::StateInterface::vfptr = (UFG::StateInterfaceVtbl *)&UFG::AvoidanceController::`vftable{for `UFG::StateInterface};
  this->mParams.MaxUpdateTimePerFrame = 0.0024999999;
  this->mParams.MMFrontDP.x = -0.1;
  this->mParams.MMFrontDP.y = 0.80000001;
  this->mParams.MMLateralVel = (UFG::qVector2)0x40000000i64;
  this->mParams.MMDistance.x = 10.0;
  this->mParams.MMDistance.y = 2.0;
  this->mParams.MMLateralDist.x = 15.0;
  this->mParams.MMLateralDist.y = 3.0;
  this->mParams.MMSecondsToImpact.x = 2.0;
  this->mParams.MMSecondsToImpact.y = 0.2;
  this->mActiveAvoidPairs.p = 0i64;
  *(_QWORD *)&this->mActiveAvoidPairs.size = 0i64;
  UFG::qArray<UFG::AvoidPairInstance,0>::Reallocate(&this->mActiveAvoidPairs, 0x20u, "qArray.Reallocate(Constructor)");
  this->mActiveAvoidPairs.size = 32;
  this->mNumActivePairs = 0;
  this->mpTransform.mPrev = &this->mpTransform;
  this->mpTransform.mNext = &this->mpTransform;
  this->mpTransform.m_pPointer = 0i64;
  mPrev = UFG::AvoidanceController::s_AvoidanceControllerList.mNode.mPrev;
  UFG::AvoidanceController::s_AvoidanceControllerList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::AvoidanceController,UFG::AvoidanceController>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::AvoidanceController,UFG::AvoidanceController> *)&UFG::AvoidanceController::s_AvoidanceControllerList;
  UFG::AvoidanceController::s_AvoidanceControllerList.mNode.mPrev = &this->UFG::qNode<UFG::AvoidanceController,UFG::AvoidanceController>;
  UFG::SimComponent::AddType(this, UFG::AvoidanceController::_AvoidanceControllerTypeUID, "AvoidanceController");
  for ( i = 0i64; i < 32; i += 8i64 )
  {
    this->mActiveAvoidPairs.p[i].mbDeleteFieldPrint = 0;
    this->mActiveAvoidPairs.p[i].mAge = 0.0;
    this->mActiveAvoidPairs.p[i].mScore = 0.0;
    p_mAvoidable = &this->mActiveAvoidPairs.p[i].mAvoidable;
    if ( p_mAvoidable->m_pPointer )
    {
      v6 = p_mAvoidable->mPrev;
      mNext = p_mAvoidable->mNext;
      v6->mNext = mNext;
      mNext->mPrev = v6;
      p_mAvoidable->mPrev = p_mAvoidable;
      p_mAvoidable->mNext = p_mAvoidable;
    }
    p_mAvoidable->m_pPointer = 0i64;
    p_mFieldPrint = &this->mActiveAvoidPairs.p[i].mFieldPrint;
    if ( p_mFieldPrint->m_pPointer )
    {
      v9 = p_mFieldPrint->mPrev;
      v10 = p_mFieldPrint->mNext;
      v9->mNext = v10;
      v10->mPrev = v9;
      p_mFieldPrint->mPrev = p_mFieldPrint;
      p_mFieldPrint->mNext = p_mFieldPrint;
    }
    p_mFieldPrint->m_pPointer = 0i64;
    this->mActiveAvoidPairs.p[i + 1].mbDeleteFieldPrint = 0;
    this->mActiveAvoidPairs.p[i + 1].mAge = 0.0;
    this->mActiveAvoidPairs.p[i + 1].mScore = 0.0;
    v11 = &this->mActiveAvoidPairs.p[i + 1].mAvoidable;
    if ( v11->m_pPointer )
    {
      v12 = v11->mPrev;
      v13 = v11->mNext;
      v12->mNext = v13;
      v13->mPrev = v12;
      v11->mPrev = v11;
      v11->mNext = v11;
    }
    v11->m_pPointer = 0i64;
    v14 = &this->mActiveAvoidPairs.p[i + 1].mFieldPrint;
    if ( v14->m_pPointer )
    {
      v15 = v14->mPrev;
      v16 = v14->mNext;
      v15->mNext = v16;
      v16->mPrev = v15;
      v14->mPrev = v14;
      v14->mNext = v14;
    }
    v14->m_pPointer = 0i64;
    this->mActiveAvoidPairs.p[i + 2].mbDeleteFieldPrint = 0;
    this->mActiveAvoidPairs.p[i + 2].mAge = 0.0;
    this->mActiveAvoidPairs.p[i + 2].mScore = 0.0;
    v17 = &this->mActiveAvoidPairs.p[i + 2].mAvoidable;
    if ( v17->m_pPointer )
    {
      v18 = v17->mPrev;
      v19 = v17->mNext;
      v18->mNext = v19;
      v19->mPrev = v18;
      v17->mPrev = v17;
      v17->mNext = v17;
    }
    v17->m_pPointer = 0i64;
    v20 = &this->mActiveAvoidPairs.p[i + 2].mFieldPrint;
    if ( v20->m_pPointer )
    {
      v21 = v20->mPrev;
      v22 = v20->mNext;
      v21->mNext = v22;
      v22->mPrev = v21;
      v20->mPrev = v20;
      v20->mNext = v20;
    }
    v20->m_pPointer = 0i64;
    this->mActiveAvoidPairs.p[i + 3].mbDeleteFieldPrint = 0;
    this->mActiveAvoidPairs.p[i + 3].mAge = 0.0;
    this->mActiveAvoidPairs.p[i + 3].mScore = 0.0;
    v23 = &this->mActiveAvoidPairs.p[i + 3].mAvoidable;
    if ( v23->m_pPointer )
    {
      v24 = v23->mPrev;
      v25 = v23->mNext;
      v24->mNext = v25;
      v25->mPrev = v24;
      v23->mPrev = v23;
      v23->mNext = v23;
    }
    v23->m_pPointer = 0i64;
    v26 = &this->mActiveAvoidPairs.p[i + 3].mFieldPrint;
    if ( v26->m_pPointer )
    {
      v27 = v26->mPrev;
      v28 = v26->mNext;
      v27->mNext = v28;
      v28->mPrev = v27;
      v26->mPrev = v26;
      v26->mNext = v26;
    }
    v26->m_pPointer = 0i64;
    this->mActiveAvoidPairs.p[i + 4].mbDeleteFieldPrint = 0;
    this->mActiveAvoidPairs.p[i + 4].mAge = 0.0;
    this->mActiveAvoidPairs.p[i + 4].mScore = 0.0;
    v29 = &this->mActiveAvoidPairs.p[i + 4].mAvoidable;
    if ( v29->m_pPointer )
    {
      v30 = v29->mPrev;
      v31 = v29->mNext;
      v30->mNext = v31;
      v31->mPrev = v30;
      v29->mPrev = v29;
      v29->mNext = v29;
    }
    v29->m_pPointer = 0i64;
    v32 = &this->mActiveAvoidPairs.p[i + 4].mFieldPrint;
    if ( v32->m_pPointer )
    {
      v33 = v32->mPrev;
      v34 = v32->mNext;
      v33->mNext = v34;
      v34->mPrev = v33;
      v32->mPrev = v32;
      v32->mNext = v32;
    }
    v32->m_pPointer = 0i64;
    this->mActiveAvoidPairs.p[i + 5].mbDeleteFieldPrint = 0;
    this->mActiveAvoidPairs.p[i + 5].mAge = 0.0;
    this->mActiveAvoidPairs.p[i + 5].mScore = 0.0;
    v35 = &this->mActiveAvoidPairs.p[i + 5].mAvoidable;
    if ( v35->m_pPointer )
    {
      v36 = v35->mPrev;
      v37 = v35->mNext;
      v36->mNext = v37;
      v37->mPrev = v36;
      v35->mPrev = v35;
      v35->mNext = v35;
    }
    v35->m_pPointer = 0i64;
    v38 = &this->mActiveAvoidPairs.p[i + 5].mFieldPrint;
    if ( v38->m_pPointer )
    {
      v39 = v38->mPrev;
      v40 = v38->mNext;
      v39->mNext = v40;
      v40->mPrev = v39;
      v38->mPrev = v38;
      v38->mNext = v38;
    }
    v38->m_pPointer = 0i64;
    this->mActiveAvoidPairs.p[i + 6].mbDeleteFieldPrint = 0;
    this->mActiveAvoidPairs.p[i + 6].mAge = 0.0;
    this->mActiveAvoidPairs.p[i + 6].mScore = 0.0;
    v41 = &this->mActiveAvoidPairs.p[i + 6].mAvoidable;
    if ( v41->m_pPointer )
    {
      v42 = v41->mPrev;
      v43 = v41->mNext;
      v42->mNext = v43;
      v43->mPrev = v42;
      v41->mPrev = v41;
      v41->mNext = v41;
    }
    v41->m_pPointer = 0i64;
    v44 = &this->mActiveAvoidPairs.p[i + 6].mFieldPrint;
    if ( v44->m_pPointer )
    {
      v45 = v44->mPrev;
      v46 = v44->mNext;
      v45->mNext = v46;
      v46->mPrev = v45;
      v44->mPrev = v44;
      v44->mNext = v44;
    }
    v44->m_pPointer = 0i64;
    this->mActiveAvoidPairs.p[i + 7].mbDeleteFieldPrint = 0;
    this->mActiveAvoidPairs.p[i + 7].mAge = 0.0;
    this->mActiveAvoidPairs.p[i + 7].mScore = 0.0;
    v47 = &this->mActiveAvoidPairs.p[i + 7].mAvoidable;
    if ( v47->m_pPointer )
    {
      v48 = v47->mPrev;
      v49 = v47->mNext;
      v48->mNext = v49;
      v49->mPrev = v48;
      v47->mPrev = v47;
      v47->mNext = v47;
    }
    v47->m_pPointer = 0i64;
    v50 = &this->mActiveAvoidPairs.p[i + 7].mFieldPrint;
    if ( v50->m_pPointer )
    {
      v51 = v50->mPrev;
      v52 = v50->mNext;
      v51->mNext = v52;
      v52->mPrev = v51;
      v50->mPrev = v50;
      v50->mNext = v50;
    }
    v50->m_pPointer = 0i64;
  }
}

// File Line: 171
// RVA: 0xFBAF0
void __fastcall UFG::AvoidanceController::~AvoidanceController(UFG::AvoidanceController *this)
{
  UFG::qNode<UFG::AvoidanceController,UFG::AvoidanceController> *v2; // rsi
  UFG::qNode<UFG::AvoidanceController,UFG::AvoidanceController> *mPrev; // rcx
  UFG::qNode<UFG::AvoidanceController,UFG::AvoidanceController> *mNext; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_mpTransform; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::AvoidPairInstance *p; // rcx
  UFG::SimComponent **p_m_pPointer; // rbx
  UFG::qNode<UFG::AvoidanceController,UFG::AvoidanceController> *v12; // rcx
  UFG::qNode<UFG::AvoidanceController,UFG::AvoidanceController> *v13; // rax

  this->UFG::StateComponentI<UFG::SimComponent>::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AvoidanceController::`vftable{for `UFG::SimComponent};
  this->UFG::StateComponentI<UFG::SimComponent>::UFG::StateInterface::vfptr = (UFG::StateInterfaceVtbl *)&UFG::AvoidanceController::`vftable{for `UFG::StateInterface};
  if ( this == UFG::AvoidanceController::s_AvoidanceControllerpCurrentIterator )
    UFG::AvoidanceController::s_AvoidanceControllerpCurrentIterator = (UFG::AvoidanceController *)&this->mPrev[-5];
  v2 = &this->UFG::qNode<UFG::AvoidanceController,UFG::AvoidanceController>;
  mPrev = this->mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  p_mpTransform = &this->mpTransform;
  if ( this->mpTransform.m_pPointer )
  {
    v6 = p_mpTransform->mPrev;
    v7 = this->mpTransform.mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    p_mpTransform->mPrev = p_mpTransform;
    this->mpTransform.mNext = &this->mpTransform;
  }
  this->mpTransform.m_pPointer = 0i64;
  v8 = p_mpTransform->mPrev;
  v9 = this->mpTransform.mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  p_mpTransform->mPrev = p_mpTransform;
  this->mpTransform.mNext = &this->mpTransform;
  p = this->mActiveAvoidPairs.p;
  if ( p )
  {
    p_m_pPointer = &p[-1].mAvoidable.m_pPointer;
    `eh vector destructor iterator(
      p,
      0x40ui64,
      (int)p[-1].mAvoidable.m_pPointer,
      (void (__fastcall *)(void *))UFG::AvoidPairInstance::~AvoidPairInstance);
    operator delete[](p_m_pPointer);
  }
  this->mActiveAvoidPairs.p = 0i64;
  *(_QWORD *)&this->mActiveAvoidPairs.size = 0i64;
  v12 = v2->mPrev;
  v13 = v2->mNext;
  v12->mNext = v13;
  v13->mPrev = v12;
  v2->mPrev = v2;
  v2->mNext = v2;
  this->UFG::StateComponentI<UFG::SimComponent>::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::StateComponentI<UFG::SimComponent>::`vftable{for `UFG::SimComponent};
  this->UFG::StateComponentI<UFG::SimComponent>::UFG::StateInterface::vfptr = (UFG::StateInterfaceVtbl *)&UFG::StateComponentI<UFG::SimComponent>::`vftable{for `UFG::StateInterface};
  if ( (this->m_Flags & 4) != 0 )
  {
    this->m_Flags |= 2u;
    ((void (__fastcall *)(UFG::AvoidanceController *))this->UFG::StateComponentI<UFG::SimComponent>::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[16].__vecDelDtor)(this);
    this->m_Flags &= ~4u;
  }
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 179
// RVA: 0x100950
void __fastcall UFG::AvoidanceController::OnAttach(UFG::AvoidanceController *this, UFG::SimObject *object)
{
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_mpTransform; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax

  if ( object )
    m_pTransformNodeComponent = object->m_pTransformNodeComponent;
  else
    m_pTransformNodeComponent = 0i64;
  p_mpTransform = &this->mpTransform;
  if ( this->mpTransform.m_pPointer )
  {
    mPrev = p_mpTransform->mPrev;
    mNext = p_mpTransform->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mpTransform->mPrev = p_mpTransform;
    p_mpTransform->mNext = p_mpTransform;
  }
  p_mpTransform->m_pPointer = m_pTransformNodeComponent;
  if ( m_pTransformNodeComponent )
  {
    v6 = m_pTransformNodeComponent->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
    v6->mNext = p_mpTransform;
    p_mpTransform->mPrev = v6;
    p_mpTransform->mNext = &m_pTransformNodeComponent->m_SafePointerList.mNode;
    m_pTransformNodeComponent->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev = p_mpTransform;
  }
}

// File Line: 188
// RVA: 0x101200
void __fastcall UFG::AvoidanceController::OnDetach(UFG::AvoidanceController *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_mpTransform; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax

  p_mpTransform = &this->mpTransform;
  if ( this->mpTransform.m_pPointer )
  {
    mPrev = p_mpTransform->mPrev;
    mNext = p_mpTransform->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mpTransform->mPrev = p_mpTransform;
    p_mpTransform->mNext = p_mpTransform;
  }
  p_mpTransform->m_pPointer = 0i64;
}

// File Line: 197
// RVA: 0x1012F0
void __fastcall UFG::AvoidanceController::OnReset(UFG::AvoidanceController *this)
{
  __int64 i; // rbx
  UFG::AvoidPairInstance *p; // rdi
  UFG::FlowfieldPrint *v4; // rcx
  UFG::FlowfieldPrint *m_pPointer; // rax
  UFG::qSafePointer<UFG::FlowfieldPrint,UFG::FlowfieldPrint> *p_mFieldPrint; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AIInterestComponent> *p_mAvoidable; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax

  this->mNumActivePairs = 0;
  for ( i = 0i64; i < 32; ++i )
  {
    p = this->mActiveAvoidPairs.p;
    if ( p[i].mbDeleteFieldPrint && (v4 = p[i].mFieldPrint.m_pPointer) != 0i64 )
    {
      v4->vfptr->__vecDelDtor(v4, 1u);
    }
    else
    {
      m_pPointer = p[i].mFieldPrint.m_pPointer;
      if ( m_pPointer )
        m_pPointer->m_Enabled = 0;
    }
    p_mFieldPrint = &p[i].mFieldPrint;
    if ( p_mFieldPrint->m_pPointer )
    {
      mPrev = p_mFieldPrint->mPrev;
      mNext = p_mFieldPrint->mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_mFieldPrint->mPrev = p_mFieldPrint;
      p_mFieldPrint->mNext = p_mFieldPrint;
    }
    p_mFieldPrint->m_pPointer = 0i64;
    p_mAvoidable = &p[i].mAvoidable;
    if ( p_mAvoidable->m_pPointer )
    {
      v10 = p_mAvoidable->mPrev;
      v11 = p_mAvoidable->mNext;
      v10->mNext = v11;
      v11->mPrev = v10;
      p_mAvoidable->mPrev = p_mAvoidable;
      p_mAvoidable->mNext = p_mAvoidable;
    }
    p_mAvoidable->m_pPointer = 0i64;
    p[i].mbDeleteFieldPrint = 0;
    *(_QWORD *)&p[i].mScore = 0i64;
  }
}

// File Line: 210
// RVA: 0x101930
void __fastcall UFG::AvoidanceController::OnUpdate(UFG::AvoidanceController *this, float fDeltaT)
{
  __int64 v2; // rsi
  float mOverallAvoidScore; // xmm0_4
  UFG::AvoidPairInstance *v6; // rbx
  float mAge; // xmm0_4
  UFG::AIInterestComponent *m_pPointer; // rdx
  float mScore; // xmm0_4
  float v10; // xmm1_4

  v2 = 0i64;
  this->mOverallAvoidScore = 0.0;
  mOverallAvoidScore = UFG::AvoidanceController::AddCloseAvoidables_ALL(this);
  if ( mOverallAvoidScore >= this->mOverallAvoidScore )
    mOverallAvoidScore = this->mOverallAvoidScore;
  this->mOverallAvoidScore = mOverallAvoidScore;
  do
  {
    v6 = &this->mActiveAvoidPairs.p[v2];
    mAge = v6->mAge;
    if ( mAge > 0.0 )
    {
      m_pPointer = (UFG::AIInterestComponent *)v6->mAvoidable.m_pPointer;
      if ( !m_pPointer
        || (mAge != 0.000099999997
          ? (mScore = UFG::AvoidanceController::ShouldAvoid(this, m_pPointer), v6->mScore = mScore)
          : (mScore = v6->mScore),
            v6->mAge = fDeltaT + v6->mAge,
            mScore == 0.0) )
      {
        UFG::AvoidPairInstance::Clear(v6);
        --this->mNumActivePairs;
      }
      else
      {
        v10 = this->mOverallAvoidScore;
        if ( v10 <= mScore )
          v10 = mScore;
        this->mOverallAvoidScore = v10;
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
  float i; // xmm6_4
  float v4; // xmm0_4

  v1 = (UFG::AIInterestComponent *)&UFG::AIInterestComponent::s_AIInterestComponentList.mNode.mNext[-5];
  for ( i = 0.0;
        v1 != (UFG::AIInterestComponent *)(&UFG::AIInterestComponent::s_AIInterestComponentList - 5);
        v1 = (UFG::AIInterestComponent *)&v1->mNext[-5] )
  {
    if ( v1->m_pSimObject != this->m_pSimObject )
    {
      v4 = UFG::AvoidanceController::AddCloseAvoidable(this, v1);
      if ( i <= v4 )
        i = v4;
      if ( this->mNumActivePairs == 32 )
        break;
    }
  }
  return i;
}

// File Line: 263
// RVA: 0x102470
float __fastcall UFG::AvoidanceController::ShouldAvoid(
        UFG::AvoidanceController *this,
        UFG::AIInterestComponent *pAvoidable)
{
  UFG::SimComponent *m_pPointer; // rbp
  float v5; // xmm6_4
  UFG::TransformNodeComponent *v6; // rbx
  float v7; // xmm12_4
  __m128 y_low; // xmm10
  float v9; // xmm13_4
  __m128 v10; // xmm2
  float x; // xmm1_4
  float v12; // xmm7_4
  float v13; // xmm9_4
  UFG::SimComponent *v14; // rbx
  float v15; // xmm3_4
  __m128 vfptr_high; // xmm4
  float v17; // xmm5_4
  __m128 v18; // xmm2
  float v19; // xmm1_4
  float v20; // xmm3_4
  float y; // xmm4_4
  float z; // xmm5_4
  UFG::TransformNodeComponent *v23; // rbx
  float v24; // xmm7_4
  float v25; // xmm1_4
  float v26; // xmm7_4
  UFG::SimComponent *v27; // rbx
  float v28; // xmm1_4
  float v29; // xmm2_4
  UFG::SimComponent *v30; // rbx
  float v31; // xmm1_4
  float v32; // xmm0_4
  float v33; // xmm0_4
  float v34; // xmm2_4
  float v35; // xmm1_4
  __m128 v36; // xmm3
  float v37; // xmm11_4
  UFG::TransformNodeComponent *v38; // rbx
  float v39; // xmm10_4
  UFG::qVector3 v1; // [rsp+30h] [rbp-B8h] BYREF
  UFG::qVector3 v0; // [rsp+40h] [rbp-A8h] BYREF
  UFG::qVector3 result; // [rsp+50h] [rbp-98h] BYREF

  if ( pAvoidable && (pAvoidable->mFlags & 1) != 0 && (pAvoidable->mFlags & 0x10) != 0 )
  {
    m_pPointer = pAvoidable->mpTransform.m_pPointer;
    v5 = 0.0;
    UFG::AIInterestComponent::GetCenter(pAvoidable, &result, 0.0);
    v6 = (UFG::TransformNodeComponent *)this->mpTransform.m_pPointer;
    UFG::TransformNodeComponent::UpdateWorldTransform(v6);
    y_low = (__m128)LODWORD(result.y);
    v7 = result.x - v6->mWorldTransform.v3.x;
    y_low.m128_f32[0] = result.y - v6->mWorldTransform.v3.y;
    v9 = result.z - v6->mWorldTransform.v3.z;
    v10 = y_low;
    v10.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v7 * v7)) + (float)(v9 * v9);
    x = this->mParams.MMDistance.x;
    v12 = _mm_sqrt_ps(v10).m128_f32[0];
    if ( v12 >= x )
      return v5;
    v13 = (float)(v12 - x) / (float)(this->mParams.MMDistance.y - x);
    if ( v13 <= 0.0 )
    {
      v13 = 0.0;
    }
    else if ( v13 >= 1.0 )
    {
      v13 = *(float *)&FLOAT_1_0;
    }
    v14 = this->mpTransform.m_pPointer;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v14);
    v15 = *(float *)&v14[4].vfptr;
    vfptr_high = (__m128)HIDWORD(v14[4].vfptr);
    v17 = *(float *)&v14[4].m_SafePointerList.mNode.mPrev;
    v18 = vfptr_high;
    v18.m128_f32[0] = (float)((float)(vfptr_high.m128_f32[0] * vfptr_high.m128_f32[0]) + (float)(v15 * v15))
                    + (float)(v17 * v17);
    v19 = _mm_sqrt_ps(v18).m128_f32[0];
    if ( v19 <= 15.0 )
    {
      v23 = (UFG::TransformNodeComponent *)this->mpTransform.m_pPointer;
      UFG::TransformNodeComponent::UpdateWorldTransform(v23);
      v20 = v23->mWorldTransform.v0.x;
      y = v23->mWorldTransform.v0.y;
      z = v23->mWorldTransform.v0.z;
    }
    else
    {
      v20 = v15 * (float)(1.0 / v19);
      y = vfptr_high.m128_f32[0] * (float)(1.0 / v19);
      z = v17 * (float)(1.0 / v19);
    }
    v24 = (float)((float)((float)((float)(1.0 / v12) * y_low.m128_f32[0]) * y)
                + (float)((float)((float)(1.0 / v12) * v7) * v20))
        + (float)((float)((float)(1.0 / v12) * v9) * z);
    v25 = this->mParams.MMFrontDP.x;
    if ( v24 <= v25 )
      return v5;
    v26 = (float)(v24 - v25) / (float)(this->mParams.MMFrontDP.y - v25);
    if ( v26 <= 0.0 )
    {
      v26 = 0.0;
    }
    else if ( v26 >= 1.0 )
    {
      v26 = *(float *)&FLOAT_1_0;
    }
    if ( (pAvoidable->mFlags & 0x100) != 0 )
    {
      if ( v26 >= v13 )
        return v13;
    }
    else
    {
      v27 = this->mpTransform.m_pPointer;
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v27);
      v28 = *((float *)&v27[4].vfptr + 1);
      v29 = *(float *)&v27[4].m_SafePointerList.mNode.mPrev;
      v1.x = *(float *)&v27[4].vfptr;
      v1.y = v28;
      v1.z = v29;
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)m_pPointer);
      v30 = this->mpTransform.m_pPointer;
      v31 = *((float *)&m_pPointer[4].vfptr + 1);
      v0.x = *(float *)&m_pPointer[4].vfptr;
      v32 = *(float *)&m_pPointer[4].m_SafePointerList.mNode.mPrev;
      v0.y = v31;
      v0.z = v32;
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v30);
      v33 = UFG::ClosingTime(&result, &v0, (UFG::qVector3 *)&v30[2].m_BoundComponentHandles, &v1, 0i64);
      v34 = this->mParams.MMSecondsToImpact.x;
      if ( v33 >= v34 )
      {
        v36 = (__m128)LODWORD(v1.y);
        v36.m128_f32[0] = (float)((float)((float)(v1.y - v0.y) * (float)(v1.y - v0.y))
                                + (float)((float)(v1.x - v0.x) * (float)(v1.x - v0.x)))
                        + (float)((float)(v1.z - v0.z) * (float)(v1.z - v0.z));
        v37 = (float)(_mm_sqrt_ps(v36).m128_f32[0] - this->mParams.MMLateralVel.x)
            / (float)(this->mParams.MMLateralVel.y - this->mParams.MMLateralVel.x);
        if ( v37 <= 0.0 )
        {
          v37 = 0.0;
        }
        else if ( v37 >= 1.0 )
        {
          v37 = *(float *)&FLOAT_1_0;
        }
        v38 = (UFG::TransformNodeComponent *)this->mpTransform.m_pPointer;
        UFG::TransformNodeComponent::UpdateWorldTransform(v38);
        v39 = (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(
                                     (float)((float)(y_low.m128_f32[0] * v38->mWorldTransform.v1.y)
                                           + (float)(v7 * v38->mWorldTransform.v1.x))
                                   + (float)(v9 * v38->mWorldTransform.v1.z)) & _xmm)
                    - this->mParams.MMLateralDist.x)
            / (float)(this->mParams.MMLateralDist.y - this->mParams.MMLateralDist.x);
        if ( v39 > 0.0 )
        {
          v5 = v39;
          if ( v39 >= 1.0 )
            v5 = *(float *)&FLOAT_1_0;
        }
        v5 = v5 * v37;
      }
      else
      {
        v35 = (float)(v33 - v34) / (float)(this->mParams.MMSecondsToImpact.y - v34);
        if ( v35 > 0.0 )
        {
          v5 = (float)(v33 - v34) / (float)(this->mParams.MMSecondsToImpact.y - v34);
          if ( v35 >= 1.0 )
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
float __fastcall UFG::AvoidanceController::AddCloseAvoidable(
        UFG::AvoidanceController *this,
        UFG::AIInterestComponent *pAvoidable)
{
  int v2; // ebx
  UFG::SimComponent **p_m_pPointer; // rax
  __int64 i; // r8
  float result; // xmm0_4
  __int64 v8; // rcx
  UFG::AvoidPairInstance *p; // rdx
  float *j; // rax
  unsigned __int64 v11; // rbx
  float *k; // rax

  v2 = 0;
  p_m_pPointer = &this->mActiveAvoidPairs.p->mAvoidable.m_pPointer;
  for ( i = 0i64; i < 32; ++i )
  {
    if ( *((float *)p_m_pPointer - 13) > 0.0 && pAvoidable == *p_m_pPointer )
      return 0.0;
    p_m_pPointer += 8;
  }
  result = UFG::AvoidanceController::ShouldAvoid(this, pAvoidable);
  if ( result > 0.0 )
  {
    v8 = 0i64;
    if ( this->mNumActivePairs == 32 )
    {
      p = this->mActiveAvoidPairs.p;
      for ( j = &p->mScore; (float)(result * 0.75) <= *j; j += 16 )
      {
        ++v8;
        ++v2;
        if ( v8 >= 32 )
          return 0.0;
      }
      this->mNumActivePairs = 31;
      UFG::AvoidPairInstance::Clear(&p[(unsigned __int64)(unsigned int)v2]);
    }
    else
    {
      for ( k = &this->mActiveAvoidPairs.p->mAge; *k > 0.0; k += 16 )
      {
        ++v8;
        ++v2;
        if ( v8 >= 32 )
          return 0.0;
      }
    }
    if ( v2 < 0 )
    {
      return 0.0;
    }
    else
    {
      v11 = (unsigned __int64)(unsigned int)v2 << 6;
      UFG::AvoidPairInstance::Init(
        (UFG::AvoidPairInstance *)((char *)this->mActiveAvoidPairs.p + v11),
        this->m_pSimObject,
        pAvoidable);
      *(float *)((char *)&this->mActiveAvoidPairs.p->mScore + v11) = result;
      ++this->mNumActivePairs;
    }
  }
  return result;
}

