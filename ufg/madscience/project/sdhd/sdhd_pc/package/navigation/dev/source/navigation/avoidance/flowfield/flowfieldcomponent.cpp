// File Line: 30
// RVA: 0x14613E0
__int64 dynamic_initializer_for__UFG::FlowfieldComponent::s_FlowfieldComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::FlowfieldComponent::s_FlowfieldComponentList__);
}

// File Line: 31
// RVA: 0xFDA00
UFG::ComponentIDDesc *__fastcall UFG::FlowfieldComponent::GetDesc(UFG::FlowfieldComponent *this)
{
  return &UFG::FlowfieldComponent::_TypeIDesc;
}

// File Line: 43
// RVA: 0xFB150
void __fastcall UFG::FlowfieldComponent::FlowfieldComponent(UFG::FlowfieldComponent *this, unsigned int name_uid)
{
  float y; // xmm1_4
  float z; // xmm2_4
  float v5; // xmm1_4
  float v6; // xmm2_4
  UFG::qNode<UFG::FlowfieldComponent,UFG::FlowfieldComponent> *mPrev; // rax

  UFG::SimComponent::SimComponent(this, name_uid);
  this->UFG::StateComponentI<UFG::SimComponent>::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::StateComponentI<UFG::SimComponent>::`vftable{for `UFG::SimComponent};
  this->UFG::StateComponentI<UFG::SimComponent>::UFG::StateInterface::vfptr = (UFG::StateInterfaceVtbl *)&UFG::StateComponentI<UFG::SimComponent>::`vftable{for `UFG::StateInterface};
  this->mAutoActivate = 1;
  this->mAge = 0.0;
  this->UFG::qNode<UFG::FlowfieldComponent,UFG::FlowfieldComponent>::mPrev = &this->UFG::qNode<UFG::FlowfieldComponent,UFG::FlowfieldComponent>;
  this->UFG::qNode<UFG::FlowfieldComponent,UFG::FlowfieldComponent>::mNext = &this->UFG::qNode<UFG::FlowfieldComponent,UFG::FlowfieldComponent>;
  this->UFG::qDebugable<UFG::FlowfieldComponent>::UFG::qNode<UFG::qDebugable<UFG::FlowfieldComponent>,UFG::qDebugable<UFG::FlowfieldComponent> >::mPrev = &this->UFG::qDebugable<UFG::FlowfieldComponent>;
  this->UFG::qDebugable<UFG::FlowfieldComponent>::UFG::qNode<UFG::qDebugable<UFG::FlowfieldComponent>,UFG::qDebugable<UFG::FlowfieldComponent> >::mNext = &this->UFG::qDebugable<UFG::FlowfieldComponent>;
  this->mThisRef = this;
  this->UFG::StateComponentI<UFG::SimComponent>::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::FlowfieldComponent::`vftable{for `UFG::SimComponent};
  this->UFG::StateComponentI<UFG::SimComponent>::UFG::StateInterface::vfptr = (UFG::StateInterfaceVtbl *)&UFG::FlowfieldComponent::`vftable{for `UFG::StateInterface};
  this->m_Prints.mNode.mPrev = &this->m_Prints.mNode;
  this->m_Prints.mNode.mNext = &this->m_Prints.mNode;
  this->mTimeOffset = 0.0;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->mEyePosition.x = UFG::qVector3::msZero.x;
  this->mEyePosition.y = y;
  this->mEyePosition.z = z;
  v5 = UFG::qVector3::msZero.y;
  v6 = UFG::qVector3::msZero.z;
  this->mEyeVelocity.x = UFG::qVector3::msZero.x;
  this->mEyeVelocity.y = v5;
  this->mEyeVelocity.z = v6;
  this->mAvoidSkill = 1.0;
  this->mpTransform.mPrev = &this->mpTransform;
  this->mpTransform.mNext = &this->mpTransform;
  this->mpTransform.m_pPointer = 0i64;
  UFG::SimComponent::AddType(this, UFG::FlowfieldComponent::_FlowfieldComponentTypeUID, "FlowfieldComponent");
  mPrev = UFG::FlowfieldComponent::s_FlowfieldComponentList.mNode.mPrev;
  UFG::FlowfieldComponent::s_FlowfieldComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::FlowfieldComponent,UFG::FlowfieldComponent>;
  this->UFG::qNode<UFG::FlowfieldComponent,UFG::FlowfieldComponent>::mPrev = mPrev;
  this->UFG::qNode<UFG::FlowfieldComponent,UFG::FlowfieldComponent>::mNext = (UFG::qNode<UFG::FlowfieldComponent,UFG::FlowfieldComponent> *)&UFG::FlowfieldComponent::s_FlowfieldComponentList;
  UFG::FlowfieldComponent::s_FlowfieldComponentList.mNode.mPrev = &this->UFG::qNode<UFG::FlowfieldComponent,UFG::FlowfieldComponent>;
  *(_WORD *)this->mTypeEnabled = 257;
  this->mTypeEnabled[2] = 1;
}

// File Line: 57
// RVA: 0xFBC60
void __fastcall UFG::FlowfieldComponent::~FlowfieldComponent(UFG::FlowfieldComponent *this)
{
  UFG::qNode<UFG::FlowfieldComponent,UFG::FlowfieldComponent> *p_mNext; // rcx
  UFG::qNode<UFG::FlowfieldComponent,UFG::FlowfieldComponent> *v3; // rdi
  __int64 v4; // rbx
  UFG::FlowfieldComponent *i; // rax
  UFG::SimObject **p_m_pSimObject; // rdx
  UFG::SimObject *m_pSimObject; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rax
  UFG::qNode<UFG::FlowfieldComponent,UFG::FlowfieldComponent> *v9; // rcx
  UFG::qNode<UFG::FlowfieldComponent,UFG::FlowfieldComponent> *mNext; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_mpTransform; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rax
  UFG::qNode<UFG::qDebugable<UFG::FlowfieldComponent>,UFG::qDebugable<UFG::FlowfieldComponent> > *v16; // rcx
  UFG::qNode<UFG::qDebugable<UFG::FlowfieldComponent>,UFG::qDebugable<UFG::FlowfieldComponent> > *v17; // rax
  UFG::qNode<UFG::FlowfieldComponent,UFG::FlowfieldComponent> *v18; // rcx
  UFG::qNode<UFG::FlowfieldComponent,UFG::FlowfieldComponent> *v19; // rax

  this->UFG::StateComponentI<UFG::SimComponent>::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::FlowfieldComponent::`vftable{for `UFG::SimComponent};
  this->UFG::StateComponentI<UFG::SimComponent>::UFG::StateInterface::vfptr = (UFG::StateInterfaceVtbl *)&UFG::FlowfieldComponent::`vftable{for `UFG::StateInterface};
  p_mNext = (UFG::qNode<UFG::FlowfieldComponent,UFG::FlowfieldComponent> *)&this->m_Prints.mNode.mNext[-3].mNext;
  v3 = &this->UFG::qNode<UFG::FlowfieldComponent,UFG::FlowfieldComponent>;
  if ( p_mNext != &this->UFG::qNode<UFG::FlowfieldComponent,UFG::FlowfieldComponent> )
  {
    do
    {
      v4 = (__int64)&p_mNext[3].mPrev[-3].mNext;
      if ( BYTE1(p_mNext[5].mPrev) )
        ((void (__fastcall *)(UFG::qNode<UFG::FlowfieldComponent,UFG::FlowfieldComponent> *, __int64))p_mNext->mPrev->mPrev)(
          p_mNext,
          1i64);
      p_mNext = (UFG::qNode<UFG::FlowfieldComponent,UFG::FlowfieldComponent> *)v4;
    }
    while ( (UFG::qNode<UFG::FlowfieldComponent,UFG::FlowfieldComponent> *)v4 != v3 );
  }
  for ( i = (UFG::FlowfieldComponent *)&this->m_Prints.mNode.mNext[-3].mNext;
        i != (UFG::FlowfieldComponent *)&this->UFG::qNode<UFG::FlowfieldComponent,UFG::FlowfieldComponent>;
        i = (UFG::FlowfieldComponent *)&this->m_Prints.mNode.mNext[-3].mNext )
  {
    p_m_pSimObject = &i->m_pSimObject;
    m_pSimObject = i->m_pSimObject;
    mPrev = i->m_BoundComponentHandles.mNode.UFG::StateComponentI<UFG::SimComponent>::UFG::SimComponent::mPrev;
    m_pSimObject->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)mPrev;
    mPrev->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)m_pSimObject;
    *p_m_pSimObject = (UFG::SimObject *)p_m_pSimObject;
    p_m_pSimObject[1] = (UFG::SimObject *)p_m_pSimObject;
  }
  if ( this == UFG::FlowfieldComponent::s_FlowfieldComponentpCurrentIterator )
    UFG::FlowfieldComponent::s_FlowfieldComponentpCurrentIterator = (UFG::FlowfieldComponent *)&v3->mPrev[-5];
  v9 = v3->mPrev;
  mNext = this->UFG::qNode<UFG::FlowfieldComponent,UFG::FlowfieldComponent>::mNext;
  v9->mNext = mNext;
  mNext->mPrev = v9;
  v3->mPrev = v3;
  this->UFG::qNode<UFG::FlowfieldComponent,UFG::FlowfieldComponent>::mNext = &this->UFG::qNode<UFG::FlowfieldComponent,UFG::FlowfieldComponent>;
  p_mpTransform = &this->mpTransform;
  if ( this->mpTransform.m_pPointer )
  {
    v12 = p_mpTransform->mPrev;
    v13 = this->mpTransform.mNext;
    v12->mNext = v13;
    v13->mPrev = v12;
    p_mpTransform->mPrev = p_mpTransform;
    this->mpTransform.mNext = &this->mpTransform;
  }
  this->mpTransform.m_pPointer = 0i64;
  v14 = p_mpTransform->mPrev;
  v15 = this->mpTransform.mNext;
  v14->mNext = v15;
  v15->mPrev = v14;
  p_mpTransform->mPrev = p_mpTransform;
  this->mpTransform.mNext = &this->mpTransform;
  UFG::qList<AimingSoftLockTask,AimingSoftLockList,0,0>::~qList<AimingSoftLockTask,AimingSoftLockList,0,0>(&this->m_Prints);
  v16 = this->UFG::qDebugable<UFG::FlowfieldComponent>::UFG::qNode<UFG::qDebugable<UFG::FlowfieldComponent>,UFG::qDebugable<UFG::FlowfieldComponent> >::mPrev;
  v17 = this->UFG::qDebugable<UFG::FlowfieldComponent>::UFG::qNode<UFG::qDebugable<UFG::FlowfieldComponent>,UFG::qDebugable<UFG::FlowfieldComponent> >::mNext;
  v16->mNext = v17;
  v17->mPrev = v16;
  this->UFG::qDebugable<UFG::FlowfieldComponent>::UFG::qNode<UFG::qDebugable<UFG::FlowfieldComponent>,UFG::qDebugable<UFG::FlowfieldComponent> >::mPrev = &this->UFG::qDebugable<UFG::FlowfieldComponent>;
  this->UFG::qDebugable<UFG::FlowfieldComponent>::UFG::qNode<UFG::qDebugable<UFG::FlowfieldComponent>,UFG::qDebugable<UFG::FlowfieldComponent> >::mNext = &this->UFG::qDebugable<UFG::FlowfieldComponent>;
  v18 = v3->mPrev;
  v19 = this->UFG::qNode<UFG::FlowfieldComponent,UFG::FlowfieldComponent>::mNext;
  v18->mNext = v19;
  v19->mPrev = v18;
  v3->mPrev = v3;
  this->UFG::qNode<UFG::FlowfieldComponent,UFG::FlowfieldComponent>::mNext = &this->UFG::qNode<UFG::FlowfieldComponent,UFG::FlowfieldComponent>;
  this->UFG::StateComponentI<UFG::SimComponent>::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::StateComponentI<UFG::SimComponent>::`vftable{for `UFG::SimComponent};
  this->UFG::StateComponentI<UFG::SimComponent>::UFG::StateInterface::vfptr = (UFG::StateInterfaceVtbl *)&UFG::StateComponentI<UFG::SimComponent>::`vftable{for `UFG::StateInterface};
  if ( (this->m_Flags & 4) != 0 )
  {
    this->m_Flags |= 2u;
    ((void (__fastcall *)(UFG::FlowfieldComponent *))this->UFG::StateComponentI<UFG::SimComponent>::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[16].__vecDelDtor)(this);
    this->m_Flags &= ~4u;
  }
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 89
// RVA: 0x1009B0
void __fastcall UFG::FlowfieldComponent::OnAttach(UFG::FlowfieldComponent *this, UFG::SimObject *object)
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

// File Line: 106
// RVA: 0x101230
void __fastcall UFG::FlowfieldComponent::OnDetach(UFG::FlowfieldComponent *this)
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

// File Line: 122
// RVA: 0x1013C0
void __fastcall UFG::FlowfieldComponent::OnReset(UFG::FlowfieldComponent *this)
{
  float y; // xmm1_4
  float z; // xmm2_4
  float v3; // xmm1_4
  float v4; // xmm2_4

  *(_WORD *)this->mTypeEnabled = 257;
  this->mTypeEnabled[2] = 1;
  this->mTimeOffset = 0.0;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->mEyePosition.x = UFG::qVector3::msZero.x;
  this->mEyePosition.y = y;
  this->mEyePosition.z = z;
  v3 = UFG::qVector3::msZero.y;
  v4 = UFG::qVector3::msZero.z;
  this->mEyeVelocity.x = UFG::qVector3::msZero.x;
  this->mEyeVelocity.y = v3;
  this->mEyeVelocity.z = v4;
}

// File Line: 146
// RVA: 0x101A20
void __fastcall UFG::FlowfieldComponent::OnUpdate(UFG::FlowfieldComponent *this, float fDeltaT)
{
  UFG::SimComponent *m_pPointer; // rbx
  float v4; // xmm0_4
  float v5; // xmm1_4
  UFG::SimComponent *v6; // rbx
  float v7; // xmm0_4
  float v8; // xmm1_4
  float y; // xmm1_4
  float z; // xmm2_4
  float v11; // xmm1_4
  float v12; // xmm2_4

  m_pPointer = this->mpTransform.m_pPointer;
  if ( m_pPointer )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->mpTransform.m_pPointer);
    v4 = *((float *)&m_pPointer[2].m_BoundComponentHandles.mNode.mPrev + 1);
    v5 = *(float *)&m_pPointer[2].m_BoundComponentHandles.mNode.mNext;
    this->mEyePosition.x = *(float *)&m_pPointer[2].m_BoundComponentHandles.mNode.mPrev;
    this->mEyePosition.y = v4;
    this->mEyePosition.z = v5;
    v6 = this->mpTransform.m_pPointer;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v6);
    v7 = *((float *)&v6[4].vfptr + 1);
    v8 = *(float *)&v6[4].m_SafePointerList.mNode.mPrev;
    this->mEyeVelocity.x = *(float *)&v6[4].vfptr;
    this->mEyeVelocity.y = v7;
    this->mEyeVelocity.z = v8;
  }
  else
  {
    y = UFG::qVector3::msZero.y;
    z = UFG::qVector3::msZero.z;
    this->mEyePosition.x = UFG::qVector3::msZero.x;
    this->mEyePosition.y = y;
    this->mEyePosition.z = z;
    v11 = UFG::qVector3::msZero.y;
    v12 = UFG::qVector3::msZero.z;
    this->mEyeVelocity.x = UFG::qVector3::msZero.x;
    this->mEyeVelocity.y = v11;
    this->mEyeVelocity.z = v12;
  }
}

// File Line: 163
// RVA: 0x100FE0
void __fastcall UFG::FlowfieldComponent::OnDebugDraw(UFG::FlowfieldComponent *this, float fDeltaT, Render::View *pView)
{
  __int64 v3; // rdx
  UFG::SimComponent *m_pPointer; // rbx
  float x; // xmm7_4
  float y; // xmm8_4
  float z; // xmm9_4
  float v10; // xmm10_4
  float v11; // xmm11_4
  float v12; // xmm12_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  UFG::SimComponent *v15; // rbx
  float v16; // xmm0_4
  float v17; // xmm1_4
  UFG::FlowfieldComponent *i; // rbx

  m_pPointer = this->mpTransform.m_pPointer;
  x = this->mEyePosition.x;
  y = this->mEyePosition.y;
  z = this->mEyePosition.z;
  v10 = this->mEyeVelocity.x;
  v11 = this->mEyeVelocity.y;
  v12 = this->mEyeVelocity.z;
  if ( m_pPointer )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->mpTransform.m_pPointer);
    v13 = *((float *)&m_pPointer[2].m_BoundComponentHandles.mNode.mPrev + 1);
    v14 = *(float *)&m_pPointer[2].m_BoundComponentHandles.mNode.mNext;
    this->mEyePosition.x = *(float *)&m_pPointer[2].m_BoundComponentHandles.mNode.mPrev;
    this->mEyePosition.y = v13;
    this->mEyePosition.z = v14;
    v15 = this->mpTransform.m_pPointer;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v15);
    v16 = *((float *)&v15[4].vfptr + 1);
    v17 = *(float *)&v15[4].m_SafePointerList.mNode.mPrev;
    this->mEyeVelocity.x = *(float *)&v15[4].vfptr;
    this->mEyeVelocity.y = v16;
    this->mEyeVelocity.z = v17;
  }
  for ( i = (UFG::FlowfieldComponent *)&this->m_Prints.mNode.mNext[-3].mNext;
        i != (UFG::FlowfieldComponent *)&this->UFG::qNode<UFG::FlowfieldComponent,UFG::FlowfieldComponent>;
        i = (UFG::FlowfieldComponent *)&i->m_BoundComponentHandles.mNode.UFG::StateComponentI<UFG::SimComponent>::UFG::SimComponent::mPrev[-3].mNext )
  {
    if ( LOBYTE(i->UFG::qNode<UFG::FlowfieldComponent,UFG::FlowfieldComponent>::mPrev) )
      ((void (__fastcall *)(UFG::FlowfieldComponent *, __int64, Render::View *))i->UFG::StateComponentI<UFG::SimComponent>::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[1].__vecDelDtor)(
        i,
        v3,
        pView);
  }
  this->mEyePosition.x = x;
  this->mEyePosition.y = y;
  this->mEyePosition.z = z;
  this->mEyeVelocity.x = v10;
  this->mEyeVelocity.y = v11;
  this->mEyeVelocity.z = v12;
}

// File Line: 235
// RVA: 0x1023E0
void __fastcall UFG::FlowfieldComponent::RemovePrint(UFG::FlowfieldComponent *this, UFG::FlowfieldPrint *pPrint)
{
  UFG::FlowfieldPrint *mPrev; // r8
  UFG::qNode<UFG::FlowfieldPrint,UFG::FlowfieldPrint> *v3; // rcx
  UFG::qNode<UFG::FlowfieldPrint,UFG::FlowfieldPrint> *mNext; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::FlowfieldComponent> *p_mpParentField; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax

  mPrev = (UFG::FlowfieldPrint *)pPrint->UFG::qNode<UFG::FlowfieldPrint,UFG::FlowfieldPrint>::mPrev;
  v3 = &pPrint->UFG::qNode<UFG::FlowfieldPrint,UFG::FlowfieldPrint>;
  if ( mPrev != (UFG::FlowfieldPrint *)&pPrint->UFG::qNode<UFG::FlowfieldPrint,UFG::FlowfieldPrint>
    || pPrint->UFG::qNode<UFG::FlowfieldPrint,UFG::FlowfieldPrint>::mNext != &pPrint->UFG::qNode<UFG::FlowfieldPrint,UFG::FlowfieldPrint> )
  {
    mNext = pPrint->UFG::qNode<UFG::FlowfieldPrint,UFG::FlowfieldPrint>::mNext;
    p_mpParentField = &pPrint->mpParentField;
    mPrev->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::FlowfieldPrint>::mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *)mNext;
    mNext->mPrev = (UFG::qNode<UFG::FlowfieldPrint,UFG::FlowfieldPrint> *)mPrev;
    v3->mPrev = v3;
    v3->mNext = v3;
    if ( p_mpParentField->m_pPointer )
    {
      v6 = p_mpParentField->mPrev;
      v7 = p_mpParentField->mNext;
      v6->mNext = v7;
      v7->mPrev = v6;
      p_mpParentField->mPrev = p_mpParentField;
      p_mpParentField->mNext = p_mpParentField;
    }
    p_mpParentField->m_pPointer = 0i64;
  }
}

// File Line: 259
// RVA: 0xFC950
void __fastcall UFG::FlowfieldComponent::AddPrint(
        UFG::FlowfieldComponent *this,
        UFG::FlowfieldPrint *pNewPrint,
        bool bResortPriority)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::FlowfieldComponent> *p_mpParentField; // r10
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::qList<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList,1,0> *p_m_SafePointerList; // rcx
  UFG::qNode<UFG::FlowfieldPrint,UFG::FlowfieldPrint> **p_mNext; // rax
  UFG::qList<UFG::FlowfieldPrint,UFG::FlowfieldPrint,0,1> *p_m_Prints; // rdx
  UFG::qNode<UFG::FlowfieldPrint,UFG::FlowfieldPrint> *v12; // rax

  p_mpParentField = &pNewPrint->mpParentField;
  if ( pNewPrint->mpParentField.m_pPointer )
  {
    mPrev = p_mpParentField->mPrev;
    mNext = pNewPrint->mpParentField.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mpParentField->mPrev = p_mpParentField;
    pNewPrint->mpParentField.mNext = &pNewPrint->mpParentField;
  }
  pNewPrint->mpParentField.m_pPointer = this;
  if ( this )
  {
    v8 = this->m_SafePointerList.mNode.UFG::StateComponentI<UFG::SimComponent>::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
    p_m_SafePointerList = &this->m_SafePointerList;
    v8->mNext = p_mpParentField;
    p_mpParentField->mPrev = v8;
    pNewPrint->mpParentField.mNext = &p_m_SafePointerList->mNode;
    p_m_SafePointerList->mNode.mPrev = p_mpParentField;
  }
  if ( !bResortPriority
    || (p_mNext = &this->m_Prints.mNode.mNext[-3].mNext,
        p_mNext == (UFG::qNode<UFG::FlowfieldPrint,UFG::FlowfieldPrint> **)&this->UFG::qNode<UFG::FlowfieldComponent,UFG::FlowfieldComponent>) )
  {
LABEL_9:
    p_m_Prints = &this->m_Prints;
  }
  else
  {
    while ( *((_DWORD *)p_mNext + 18) <= pNewPrint->m_iPriority )
    {
      p_mNext = &p_mNext[6][-3].mNext;
      if ( p_mNext == (UFG::qNode<UFG::FlowfieldPrint,UFG::FlowfieldPrint> **)&this->UFG::qNode<UFG::FlowfieldComponent,UFG::FlowfieldComponent> )
        goto LABEL_9;
    }
    p_m_Prints = (UFG::qList<UFG::FlowfieldPrint,UFG::FlowfieldPrint,0,1> *)(p_mNext + 5);
  }
  v12 = p_m_Prints->mNode.mPrev;
  v12->mNext = &pNewPrint->UFG::qNode<UFG::FlowfieldPrint,UFG::FlowfieldPrint>;
  pNewPrint->UFG::qNode<UFG::FlowfieldPrint,UFG::FlowfieldPrint>::mPrev = v12;
  pNewPrint->UFG::qNode<UFG::FlowfieldPrint,UFG::FlowfieldPrint>::mNext = &p_m_Prints->mNode;
  p_m_Prints->mNode.mPrev = &pNewPrint->UFG::qNode<UFG::FlowfieldPrint,UFG::FlowfieldPrint>;
}

// File Line: 315
// RVA: 0x100800
char __fastcall UFG::FlowfieldComponent::IsFlowDefinedAt(UFG::FlowfieldComponent *this, UFG::qVector3 *vPosition)
{
  UFG::qNode<UFG::FlowfieldComponent,UFG::FlowfieldComponent> *v2; // rdi
  UFG::FlowfieldComponent *p_mNext; // rbx

  v2 = &this->UFG::qNode<UFG::FlowfieldComponent,UFG::FlowfieldComponent>;
  p_mNext = (UFG::FlowfieldComponent *)&this->m_Prints.mNode.mNext[-3].mNext;
  if ( p_mNext == (UFG::FlowfieldComponent *)&this->UFG::qNode<UFG::FlowfieldComponent,UFG::FlowfieldComponent> )
    return 0;
  while ( !p_mNext->UFG::StateComponentI<UFG::SimComponent>::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[3].__vecDelDtor(
             p_mNext,
             (unsigned int)vPosition) )
  {
    p_mNext = (UFG::FlowfieldComponent *)&p_mNext->m_BoundComponentHandles.mNode.UFG::StateComponentI<UFG::SimComponent>::UFG::SimComponent::mPrev[-3].mNext;
    if ( p_mNext == (UFG::FlowfieldComponent *)v2 )
      return 0;
  }
  return 1;
}

// File Line: 328
// RVA: 0xFE390
float __fastcall UFG::FlowfieldComponent::GetFlow(
        UFG::FlowfieldComponent *this,
        UFG::qVector3 *outFlow,
        UFG::qVector3 *vPosition)
{
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::qNode<UFG::FlowfieldComponent,UFG::FlowfieldComponent> *v5; // r14
  int v9; // ebp
  float v10; // xmm6_4
  char *p_mNext; // rbx
  char v12; // al
  __int64 v13; // rcx
  double v14; // xmm0_8
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  int v22[4]; // [rsp+30h] [rbp-48h] BYREF

  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  v5 = &this->UFG::qNode<UFG::FlowfieldComponent,UFG::FlowfieldComponent>;
  v9 = 999999;
  v10 = 0.0;
  outFlow->x = UFG::qVector3::msZero.x;
  outFlow->y = y;
  outFlow->z = z;
  p_mNext = (char *)&this->m_Prints.mNode.mNext[-3].mNext;
  if ( p_mNext == (char *)&this->UFG::qNode<UFG::FlowfieldComponent,UFG::FlowfieldComponent> )
    return 0.0;
  do
  {
    v12 = p_mNext[80];
    if ( v12 )
    {
      v13 = *((_QWORD *)p_mNext + 16);
      if ( v13 )
        v12 = *(_BYTE *)(v13 + 96);
      if ( v12 )
      {
        if ( this->mTypeEnabled[*((int *)p_mNext + 7)] && v9 >= *((_DWORD *)p_mNext + 18) )
        {
          if ( (*(unsigned __int8 (__fastcall **)(char *, UFG::qVector3 *))(*(_QWORD *)p_mNext + 24i64))(
                 p_mNext,
                 vPosition) )
          {
            v14 = (*(double (__fastcall **)(char *, int *, UFG::qVector3 *))(*(_QWORD *)p_mNext + 16i64))(
                    p_mNext,
                    v22,
                    vPosition);
            if ( *(float *)&v14 > 0.0 )
            {
              if ( v9 > *((_DWORD *)p_mNext + 18) )
              {
                v15 = UFG::qVector3::msZero.y;
                v16 = UFG::qVector3::msZero.z;
                v9 = *((_DWORD *)p_mNext + 18);
                v10 = 0.0;
                outFlow->x = UFG::qVector3::msZero.x;
                outFlow->y = v15;
                outFlow->z = v16;
              }
              v17 = (float)(*(float *)&v22[1] * *(float *)&v14) + outFlow->y;
              v18 = (float)(*(float *)&v22[2] * *(float *)&v14) + outFlow->z;
              outFlow->x = (float)(*(float *)v22 * *(float *)&v14) + outFlow->x;
              outFlow->y = v17;
              outFlow->z = v18;
              v10 = v10 + *(float *)&v14;
            }
          }
        }
      }
    }
    p_mNext = (char *)(*((_QWORD *)p_mNext + 6) - 40i64);
  }
  while ( p_mNext != (char *)v5 );
  if ( v10 <= 0.0 )
    return 0.0;
  v19 = (float)(1.0 / v10) * outFlow->x;
  v20 = (float)(1.0 / v10) * outFlow->y;
  outFlow->z = (float)(1.0 / v10) * outFlow->z;
  outFlow->x = v19;
  outFlow->y = v20;
  return v10;
}

