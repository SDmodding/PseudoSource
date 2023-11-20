// File Line: 30
// RVA: 0x14613E0
__int64 dynamic_initializer_for__UFG::FlowfieldComponent::s_FlowfieldComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::FlowfieldComponent::s_FlowfieldComponentList__);
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
  UFG::FlowfieldComponent *v2; // rdi
  UFG::qNode<UFG::FlowfieldComponent,UFG::FlowfieldComponent> *v3; // rbx
  float v4; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm1_4
  float v7; // xmm2_4
  UFG::qNode<UFG::FlowfieldComponent,UFG::FlowfieldComponent> *v8; // rax
  UFG::qDebugable<UFG::FlowfieldComponent> *v9; // [rsp+50h] [rbp+18h]
  UFG::qList<UFG::FlowfieldPrint,UFG::FlowfieldPrint,0,1> *v10; // [rsp+50h] [rbp+18h]
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v11; // [rsp+50h] [rbp+18h]

  v2 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, name_uid);
  v2->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::StateComponentI<UFG::SimComponent>::`vftable{for `UFG::SimComponent};
  v2->vfptr = (UFG::StateInterfaceVtbl *)&UFG::StateComponentI<UFG::SimComponent>::`vftable{for `UFG::StateInterface};
  v2->mAutoActivate = 1;
  v2->mAge = 0.0;
  v3 = (UFG::qNode<UFG::FlowfieldComponent,UFG::FlowfieldComponent> *)&v2->mPrev;
  v3->mPrev = v3;
  v3->mNext = v3;
  v9 = (UFG::qDebugable<UFG::FlowfieldComponent> *)&v2->mPrev;
  v9->mPrev = (UFG::qNode<UFG::qDebugable<UFG::FlowfieldComponent>,UFG::qDebugable<UFG::FlowfieldComponent> > *)&v9->mPrev;
  v9->mNext = (UFG::qNode<UFG::qDebugable<UFG::FlowfieldComponent>,UFG::qDebugable<UFG::FlowfieldComponent> > *)&v9->mPrev;
  v2->mThisRef = v2;
  v2->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::FlowfieldComponent::`vftable{for `UFG::SimComponent};
  v2->vfptr = (UFG::StateInterfaceVtbl *)&UFG::FlowfieldComponent::`vftable{for `UFG::StateInterface};
  v10 = &v2->m_Prints;
  v10->mNode.mPrev = &v10->mNode;
  v10->mNode.mNext = &v10->mNode;
  v2->mTimeOffset = 0.0;
  v4 = UFG::qVector3::msZero.y;
  v5 = UFG::qVector3::msZero.z;
  v2->mEyePosition.x = UFG::qVector3::msZero.x;
  v2->mEyePosition.y = v4;
  v2->mEyePosition.z = v5;
  v6 = UFG::qVector3::msZero.y;
  v7 = UFG::qVector3::msZero.z;
  v2->mEyeVelocity.x = UFG::qVector3::msZero.x;
  v2->mEyeVelocity.y = v6;
  v2->mEyeVelocity.z = v7;
  v2->mAvoidSkill = 1.0;
  v11 = &v2->mpTransform;
  v11->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v11->mPrev;
  v11->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v11->mPrev;
  v2->mpTransform.m_pPointer = 0i64;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v2->vfptr,
    UFG::FlowfieldComponent::_FlowfieldComponentTypeUID,
    "FlowfieldComponent");
  v8 = UFG::FlowfieldComponent::s_FlowfieldComponentList.mNode.mPrev;
  UFG::FlowfieldComponent::s_FlowfieldComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::FlowfieldComponent,UFG::FlowfieldComponent> *)&v2->mPrev;
  v3->mPrev = v8;
  v2->mNext = (UFG::qNode<UFG::FlowfieldComponent,UFG::FlowfieldComponent> *)&UFG::FlowfieldComponent::s_FlowfieldComponentList;
  UFG::FlowfieldComponent::s_FlowfieldComponentList.mNode.mPrev = (UFG::qNode<UFG::FlowfieldComponent,UFG::FlowfieldComponent> *)&v2->mPrev;
  *(_WORD *)v2->mTypeEnabled = 257;
  v2->mTypeEnabled[2] = 1;
}

// File Line: 57
// RVA: 0xFBC60
void __fastcall UFG::FlowfieldComponent::~FlowfieldComponent(UFG::FlowfieldComponent *this)
{
  UFG::FlowfieldComponent *v1; // rsi
  UFG::qNode<UFG::FlowfieldComponent,UFG::FlowfieldComponent> **v2; // rcx
  UFG::qNode<UFG::FlowfieldComponent,UFG::FlowfieldComponent> *v3; // rdi
  signed __int64 v4; // rbx
  signed __int64 i; // rax
  _QWORD *v6; // rdx
  __int64 v7; // rcx
  _QWORD *v8; // rax
  UFG::qNode<UFG::FlowfieldComponent,UFG::FlowfieldComponent> *v9; // rcx
  UFG::qNode<UFG::FlowfieldComponent,UFG::FlowfieldComponent> *v10; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v11; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rax
  UFG::qDebugable<UFG::FlowfieldComponent> *v16; // rdx
  UFG::qNode<UFG::qDebugable<UFG::FlowfieldComponent>,UFG::qDebugable<UFG::FlowfieldComponent> > *v17; // rcx
  UFG::qNode<UFG::qDebugable<UFG::FlowfieldComponent>,UFG::qDebugable<UFG::FlowfieldComponent> > *v18; // rax
  UFG::qNode<UFG::FlowfieldComponent,UFG::FlowfieldComponent> *v19; // rcx
  UFG::qNode<UFG::FlowfieldComponent,UFG::FlowfieldComponent> *v20; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::FlowfieldComponent::`vftable{for `UFG::SimComponent};
  this->vfptr = (UFG::StateInterfaceVtbl *)&UFG::FlowfieldComponent::`vftable{for `UFG::StateInterface};
  v2 = (UFG::qNode<UFG::FlowfieldComponent,UFG::FlowfieldComponent> **)&this->m_Prints.mNode.mNext[-3].mNext;
  v3 = (UFG::qNode<UFG::FlowfieldComponent,UFG::FlowfieldComponent> *)&v1->mPrev;
  if ( v2 != &v1->mPrev )
  {
    do
    {
      v4 = (signed __int64)&v2[6][-3].mNext;
      if ( *((_BYTE *)v2 + 81) )
        ((void (__fastcall *)(UFG::qNode<UFG::FlowfieldComponent,UFG::FlowfieldComponent> **, signed __int64))(*v2)->mPrev)(
          v2,
          1i64);
      v2 = (UFG::qNode<UFG::FlowfieldComponent,UFG::FlowfieldComponent> **)v4;
    }
    while ( (UFG::qNode<UFG::FlowfieldComponent,UFG::FlowfieldComponent> *)v4 != v3 );
  }
  for ( i = (signed __int64)&v1->m_Prints.mNode.mNext[-3].mNext;
        (UFG::qNode<UFG::FlowfieldComponent,UFG::FlowfieldComponent> **)i != &v1->mPrev;
        i = (signed __int64)&v1->m_Prints.mNode.mNext[-3].mNext )
  {
    v6 = (_QWORD *)(i + 40);
    v7 = *(_QWORD *)(i + 40);
    v8 = *(_QWORD **)(i + 48);
    *(_QWORD *)(v7 + 8) = v8;
    *v8 = v7;
    *v6 = v6;
    v6[1] = v6;
  }
  if ( v1 == UFG::FlowfieldComponent::s_FlowfieldComponentpCurrentIterator )
    UFG::FlowfieldComponent::s_FlowfieldComponentpCurrentIterator = (UFG::FlowfieldComponent *)&v3->mPrev[-5];
  v9 = v3->mPrev;
  v10 = v1->mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  v3->mPrev = v3;
  v1->mNext = (UFG::qNode<UFG::FlowfieldComponent,UFG::FlowfieldComponent> *)&v1->mPrev;
  v11 = &v1->mpTransform;
  if ( v1->mpTransform.m_pPointer )
  {
    v12 = v11->mPrev;
    v13 = v1->mpTransform.mNext;
    v12->mNext = v13;
    v13->mPrev = v12;
    v11->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v11->mPrev;
    v1->mpTransform.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mpTransform.mPrev;
  }
  v1->mpTransform.m_pPointer = 0i64;
  v14 = v11->mPrev;
  v15 = v1->mpTransform.mNext;
  v14->mNext = v15;
  v15->mPrev = v14;
  v11->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v11->mPrev;
  v1->mpTransform.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mpTransform.mPrev;
  UFG::qList<AimingSoftLockTask,AimingSoftLockList,0,0>::~qList<AimingSoftLockTask,AimingSoftLockList,0,0>(&v1->m_Prints);
  v16 = (UFG::qDebugable<UFG::FlowfieldComponent> *)&v1->mPrev;
  v17 = v1->mPrev;
  v18 = v1->mNext;
  v17->mNext = v18;
  v18->mPrev = v17;
  v16->mPrev = (UFG::qNode<UFG::qDebugable<UFG::FlowfieldComponent>,UFG::qDebugable<UFG::FlowfieldComponent> > *)&v16->mPrev;
  v16->mNext = (UFG::qNode<UFG::qDebugable<UFG::FlowfieldComponent>,UFG::qDebugable<UFG::FlowfieldComponent> > *)&v16->mPrev;
  v19 = v3->mPrev;
  v20 = v1->mNext;
  v19->mNext = v20;
  v20->mPrev = v19;
  v3->mPrev = v3;
  v1->mNext = (UFG::qNode<UFG::FlowfieldComponent,UFG::FlowfieldComponent> *)&v1->mPrev;
  v1->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::StateComponentI<UFG::SimComponent>::`vftable{for `UFG::SimComponent};
  v1->vfptr = (UFG::StateInterfaceVtbl *)&UFG::StateComponentI<UFG::SimComponent>::`vftable{for `UFG::StateInterface};
  if ( (LOBYTE(v1->m_Flags) >> 2) & 1 )
  {
    v1->m_Flags |= 2u;
    ((void (__fastcall *)(UFG::FlowfieldComponent *))v1->vfptr[16].__vecDelDtor)(v1);
    v1->m_Flags &= 0xFFFBu;
  }
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 89
// RVA: 0x1009B0
void __fastcall UFG::FlowfieldComponent::OnAttach(UFG::FlowfieldComponent *this, UFG::SimObject *object)
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

// File Line: 106
// RVA: 0x101230
void __fastcall UFG::FlowfieldComponent::OnDetach(UFG::FlowfieldComponent *this)
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

// File Line: 122
// RVA: 0x1013C0
void __fastcall UFG::FlowfieldComponent::OnReset(UFG::FlowfieldComponent *this)
{
  float v1; // xmm1_4
  float v2; // xmm2_4
  float v3; // xmm1_4
  float v4; // xmm2_4

  *(_WORD *)this->mTypeEnabled = 257;
  this->mTypeEnabled[2] = 1;
  this->mTimeOffset = 0.0;
  v1 = UFG::qVector3::msZero.y;
  v2 = UFG::qVector3::msZero.z;
  this->mEyePosition.x = UFG::qVector3::msZero.x;
  this->mEyePosition.y = v1;
  this->mEyePosition.z = v2;
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
  UFG::SimComponent *v2; // rbx
  UFG::FlowfieldComponent *v3; // rdi
  float v4; // xmm0_4
  float v5; // xmm1_4
  UFG::SimComponent *v6; // rbx
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  float v12; // xmm2_4

  v2 = this->mpTransform.m_pPointer;
  v3 = this;
  if ( v2 )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->mpTransform.m_pPointer);
    v4 = *((float *)&v2[2].m_BoundComponentHandles.mNode.mPrev + 1);
    v5 = *(float *)&v2[2].m_BoundComponentHandles.mNode.mNext;
    v3->mEyePosition.x = *(float *)&v2[2].m_BoundComponentHandles.mNode.mPrev;
    v3->mEyePosition.y = v4;
    v3->mEyePosition.z = v5;
    v6 = v3->mpTransform.m_pPointer;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v3->mpTransform.m_pPointer);
    v7 = *((float *)&v6[4].vfptr + 1);
    v8 = *(float *)&v6[4].m_SafePointerList.mNode.mPrev;
    v3->mEyeVelocity.x = *(float *)&v6[4].vfptr;
    v3->mEyeVelocity.y = v7;
    v3->mEyeVelocity.z = v8;
  }
  else
  {
    v9 = UFG::qVector3::msZero.y;
    v10 = UFG::qVector3::msZero.z;
    this->mEyePosition.x = UFG::qVector3::msZero.x;
    this->mEyePosition.y = v9;
    this->mEyePosition.z = v10;
    v11 = UFG::qVector3::msZero.y;
    v12 = UFG::qVector3::msZero.z;
    this->mEyeVelocity.x = UFG::qVector3::msZero.x;
    this->mEyeVelocity.y = v11;
    this->mEyeVelocity.z = v12;
  }
}

// File Line: 163
// RVA: 0x100FE0
void __usercall UFG::FlowfieldComponent::OnDebugDraw(UFG::FlowfieldComponent *this@<rcx>, float fDeltaT@<xmm1>, Render::View *pView@<r8>, __int64 a4@<rdx>)
{
  UFG::SimComponent *v4; // rbx
  float v5; // xmm7_4
  Render::View *v6; // rbp
  UFG::FlowfieldComponent *v7; // rdi
  float v8; // xmm8_4
  float v9; // xmm9_4
  float v10; // xmm10_4
  float v11; // xmm11_4
  float v12; // xmm12_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  UFG::SimComponent *v15; // rbx
  float v16; // xmm0_4
  float v17; // xmm1_4
  signed __int64 i; // rbx

  v4 = this->mpTransform.m_pPointer;
  v5 = this->mEyePosition.x;
  v6 = pView;
  v7 = this;
  v8 = this->mEyePosition.y;
  v9 = this->mEyePosition.z;
  v10 = this->mEyeVelocity.x;
  v11 = this->mEyeVelocity.y;
  v12 = this->mEyeVelocity.z;
  if ( v4 )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->mpTransform.m_pPointer);
    v13 = *((float *)&v4[2].m_BoundComponentHandles.mNode.mPrev + 1);
    v14 = *(float *)&v4[2].m_BoundComponentHandles.mNode.mNext;
    v7->mEyePosition.x = *(float *)&v4[2].m_BoundComponentHandles.mNode.mPrev;
    v7->mEyePosition.y = v13;
    v7->mEyePosition.z = v14;
    v15 = v7->mpTransform.m_pPointer;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v7->mpTransform.m_pPointer);
    v16 = *((float *)&v15[4].vfptr + 1);
    v17 = *(float *)&v15[4].m_SafePointerList.mNode.mPrev;
    v7->mEyeVelocity.x = *(float *)&v15[4].vfptr;
    v7->mEyeVelocity.y = v16;
    v7->mEyeVelocity.z = v17;
  }
  for ( i = (signed __int64)&v7->m_Prints.mNode.mNext[-3].mNext;
        (UFG::qNode<UFG::FlowfieldComponent,UFG::FlowfieldComponent> **)i != &v7->mPrev;
        i = *(_QWORD *)(i + 48) - 40i64 )
  {
    if ( *(_BYTE *)(i + 80) )
      (*(void (__fastcall **)(signed __int64, __int64, Render::View *))(*(_QWORD *)i + 8i64))(i, a4, v6);
  }
  v7->mEyePosition.x = v5;
  v7->mEyePosition.y = v8;
  v7->mEyePosition.z = v9;
  v7->mEyeVelocity.x = v10;
  v7->mEyeVelocity.y = v11;
  v7->mEyeVelocity.z = v12;
}

// File Line: 235
// RVA: 0x1023E0
void __fastcall UFG::FlowfieldComponent::RemovePrint(UFG::FlowfieldComponent *this, UFG::FlowfieldPrint *pPrint)
{
  UFG::FlowfieldPrint *v2; // r8
  UFG::qNode<UFG::FlowfieldPrint,UFG::FlowfieldPrint> *v3; // rcx
  UFG::qNode<UFG::FlowfieldPrint,UFG::FlowfieldPrint> *v4; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::FlowfieldComponent> *v5; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax

  v2 = (UFG::FlowfieldPrint *)pPrint->mPrev;
  v3 = (UFG::qNode<UFG::FlowfieldPrint,UFG::FlowfieldPrint> *)&pPrint->mPrev;
  if ( v2 != (UFG::FlowfieldPrint *)&pPrint->mPrev
    || (UFG::qNode<UFG::FlowfieldPrint,UFG::FlowfieldPrint> **)pPrint->mNext != &pPrint->mPrev )
  {
    v4 = pPrint->mNext;
    v5 = &pPrint->mpParentField;
    v2->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::FlowfieldPrint>,UFG::qSafePointerNodeList> *)v4;
    v4->mPrev = (UFG::qNode<UFG::FlowfieldPrint,UFG::FlowfieldPrint> *)v2;
    v3->mPrev = v3;
    v3->mNext = v3;
    if ( v5->m_pPointer )
    {
      v6 = v5->mPrev;
      v7 = v5->mNext;
      v6->mNext = v7;
      v7->mPrev = v6;
      v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
      v5->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
    }
    v5->m_pPointer = 0i64;
  }
}

// File Line: 259
// RVA: 0xFC950
void __fastcall UFG::FlowfieldComponent::AddPrint(UFG::FlowfieldComponent *this, UFG::FlowfieldPrint *pNewPrint, bool bResortPriority)
{
  UFG::FlowfieldPrint *v3; // r11
  UFG::FlowfieldComponent *v4; // rdx
  UFG::qSafePointer<UFG::SimComponent,UFG::FlowfieldComponent> *v5; // r10
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::qList<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList,1,0> *v9; // rcx
  signed __int64 v10; // rax
  UFG::qList<UFG::FlowfieldPrint,UFG::FlowfieldPrint,0,1> *v11; // rdx
  UFG::qNode<UFG::FlowfieldPrint,UFG::FlowfieldPrint> *v12; // rax
  UFG::qNode<UFG::FlowfieldPrint,UFG::FlowfieldPrint> *v13; // rcx

  v3 = pNewPrint;
  v4 = this;
  v5 = &v3->mpParentField;
  if ( v3->mpParentField.m_pPointer )
  {
    v6 = v5->mPrev;
    v7 = v3->mpParentField.mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
    v3->mpParentField.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mpParentField.mPrev;
  }
  v3->mpParentField.m_pPointer = (UFG::SimComponent *)&this->vfptr;
  if ( this )
  {
    v8 = this->m_SafePointerList.mNode.mPrev;
    v9 = &this->m_SafePointerList;
    v8->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
    v5->mPrev = v8;
    v3->mpParentField.mNext = &v9->mNode;
    v9->mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  }
  if ( bResortPriority
    && (v10 = (signed __int64)&v4->m_Prints.mNode.mNext[-3].mNext,
        (UFG::qNode<UFG::FlowfieldComponent,UFG::FlowfieldComponent> **)v10 != &v4->mPrev) )
  {
    while ( *(_DWORD *)(v10 + 72) <= v3->m_iPriority )
    {
      v10 = *(_QWORD *)(v10 + 48) - 40i64;
      if ( (UFG::qNode<UFG::FlowfieldComponent,UFG::FlowfieldComponent> **)v10 == &v4->mPrev )
        goto LABEL_9;
    }
    v11 = (UFG::qList<UFG::FlowfieldPrint,UFG::FlowfieldPrint,0,1> *)(v10 + 40);
  }
  else
  {
LABEL_9:
    v11 = &v4->m_Prints;
  }
  v12 = v11->mNode.mPrev;
  v13 = (UFG::qNode<UFG::FlowfieldPrint,UFG::FlowfieldPrint> *)&v3->mPrev;
  v12->mNext = (UFG::qNode<UFG::FlowfieldPrint,UFG::FlowfieldPrint> *)&v3->mPrev;
  v13->mPrev = v12;
  v13->mNext = &v11->mNode;
  v11->mNode.mPrev = (UFG::qNode<UFG::FlowfieldPrint,UFG::FlowfieldPrint> *)&v3->mPrev;
}

// File Line: 315
// RVA: 0x100800
char __fastcall UFG::FlowfieldComponent::IsFlowDefinedAt(UFG::FlowfieldComponent *this, UFG::qVector3 *vPosition)
{
  UFG::qNode<UFG::FlowfieldComponent,UFG::FlowfieldComponent> *v2; // rdi
  UFG::qVector3 *v3; // rsi
  UFG::FlowfieldComponent *v4; // rbx

  v2 = (UFG::qNode<UFG::FlowfieldComponent,UFG::FlowfieldComponent> *)&this->mPrev;
  v3 = vPosition;
  v4 = (UFG::FlowfieldComponent *)&this->m_Prints.mNode.mNext[-3].mNext;
  if ( v4 == (UFG::FlowfieldComponent *)&this->mPrev )
    return 0;
  while ( !(unsigned __int8)v4->vfptr[3].__vecDelDtor(
                              (UFG::qSafePointerNode<UFG::SimComponent> *)&v4->vfptr,
                              (unsigned int)v3) )
  {
    v4 = (UFG::FlowfieldComponent *)&v4->m_BoundComponentHandles.mNode.mPrev[-3].mNext;
    if ( v4 == (UFG::FlowfieldComponent *)v2 )
      return 0;
  }
  return 1;
}

// File Line: 328
// RVA: 0xFE390
float __fastcall UFG::FlowfieldComponent::GetFlow(UFG::FlowfieldComponent *this, UFG::qVector3 *outFlow, UFG::qVector3 *vPosition)
{
  float v3; // xmm1_4
  float v4; // xmm2_4
  float v5; // xmm0_4
  UFG::qNode<UFG::FlowfieldComponent,UFG::FlowfieldComponent> *v6; // r14
  UFG::qVector3 *v7; // r15
  UFG::qVector3 *v8; // rdi
  UFG::FlowfieldComponent *v9; // rsi
  signed int v10; // ebp
  float v11; // xmm6_4
  char *v12; // rbx
  char v13; // al
  __int64 v14; // rcx
  __int128 v15; // xmm2
  __int128 v16; // xmm3
  float v17; // xmm3_4
  float v18; // xmm1_4
  float v19; // xmm2_4
  float v20; // xmm1_4
  float v21; // xmm2_4
  float v22; // xmm0_4
  float v23; // xmm1_4
  float v25; // [rsp+30h] [rbp-48h]
  float v26; // [rsp+34h] [rbp-44h]
  float v27; // [rsp+38h] [rbp-40h]

  v3 = UFG::qVector3::msZero.y;
  v4 = UFG::qVector3::msZero.z;
  v5 = UFG::qVector3::msZero.x;
  v6 = (UFG::qNode<UFG::FlowfieldComponent,UFG::FlowfieldComponent> *)&this->mPrev;
  v7 = vPosition;
  v8 = outFlow;
  v9 = this;
  v10 = 999999;
  v11 = 0.0;
  outFlow->x = UFG::qVector3::msZero.x;
  outFlow->y = v3;
  outFlow->z = v4;
  v12 = (char *)&this->m_Prints.mNode.mNext[-3].mNext;
  if ( v12 == (char *)&this->mPrev )
    return 0.0;
  do
  {
    v13 = v12[80];
    if ( v13 )
    {
      v14 = *((_QWORD *)v12 + 16);
      if ( v14 )
        v13 = *(_BYTE *)(v14 + 96);
      if ( v13 )
      {
        if ( v9->mTypeEnabled[*((signed int *)v12 + 7)] )
        {
          if ( v10 >= *((_DWORD *)v12 + 18) )
          {
            v15 = LODWORD(v9->mTimeOffset);
            if ( (*(unsigned __int8 (__fastcall **)(char *, UFG::qVector3 *))(*(_QWORD *)v12 + 24i64))(v12, v7) )
            {
              v16 = LODWORD(v9->mTimeOffset);
              (*(void (__fastcall **)(char *, float *, UFG::qVector3 *))(*(_QWORD *)v12 + 16i64))(v12, &v25, v7);
              v17 = v5;
              if ( v5 > 0.0 )
              {
                if ( v10 > *((_DWORD *)v12 + 18) )
                {
                  v18 = UFG::qVector3::msZero.y;
                  v19 = UFG::qVector3::msZero.z;
                  v10 = *((_DWORD *)v12 + 18);
                  v11 = 0.0;
                  v8->x = UFG::qVector3::msZero.x;
                  v8->y = v18;
                  v8->z = v19;
                }
                v5 = (float)(v25 * v5) + v8->x;
                v20 = (float)(v26 * v17) + v8->y;
                v21 = (float)(v27 * v17) + v8->z;
                v8->x = v5;
                v8->y = v20;
                v8->z = v21;
                v11 = v11 + v17;
              }
            }
          }
        }
      }
    }
    v12 = (char *)(*((_QWORD *)v12 + 6) - 40i64);
  }
  while ( v12 != (char *)v6 );
  if ( v11 <= 0.0 )
    return 0.0;
  v22 = (float)(1.0 / v11) * v8->x;
  v23 = (float)(1.0 / v11) * v8->y;
  v8->z = (float)(1.0 / v11) * v8->z;
  v8->x = v22;
  v8->y = v23;
  return v11;
}

