// File Line: 27
// RVA: 0x148ACB0
__int64 dynamic_initializer_for__DestructionDamageCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("DestructionDamageCondition", 0xFFFFFFFF);
  DestructionDamageCondition::sClassNameUID = result;
  return result;
}

// File Line: 37
// RVA: 0x276C90
void __fastcall DestructionDamageCondition::DestructionDamageCondition(DestructionDamageCondition *this)
{
  DestructionDamageCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&DestructionDamageCondition::`vftable;
  v1->mDamageThreshold = 0.0;
  v1->mInEqualityOperator.mValue = 3;
  v1->mDestructionObjectName = UFG::gNullQSymbolUC;
}

// File Line: 41
// RVA: 0x2813B0
char __fastcall DestructionDamageCondition::Match(DestructionDamageCondition *this, ActionContext *context)
{
  ActionContext *v2; // r14
  DestructionDamageCondition *v3; // rbp
  UFG::TransformNodeComponent *v4; // rsi
  bool i; // zf
  UFG::TransformNodeComponent *v6; // rdi
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v7; // rcx
  const char *v8; // rax
  __int64 v9; // rdx
  unsigned int v10; // ebx
  char *v11; // rax
  __int64 v12; // rax
  float v13; // xmm2_4
  char v14; // bl
  UFG::qReflectHandleBase v16; // [rsp+28h] [rbp-30h]

  v2 = context;
  v3 = this;
  v4 = UFG::SimObject::GetComponentOfType(
         context->mSimObject.m_pPointer,
         UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
         0,
         0i64);
  for ( i = v4 == 0i64; ; i = v6 == 0i64 )
  {
    if ( i )
      return 0;
    v6 = UFG::SimObject::GetComponentOfType(
           v2->mSimObject.m_pPointer,
           UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
           0,
           (UFG::SimComponent *)&v4->vfptr);
    UFG::qReflectHandleBase::qReflectHandleBase(&v16);
    v8 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v7);
    v16.mTypeUID = UFG::qStringHash64(v8, 0xFFFFFFFFFFFFFFFFui64);
    v9 = *(_QWORD *)&v4->mWorldTransform.v2.x;
    if ( v9 )
      UFG::qReflectHandleBase::operator=(&v16, (UFG::qReflectHandleBase *)(v9 + 224));
    if ( v16.mData )
    {
      v10 = v3->mDestructionObjectName.mUID;
      v11 = UFG::qReflectObject::GetName(v16.mData);
      if ( v10 == (unsigned int)UFG::qStringHashUpper32(v11, 0xFFFFFFFF) || v3->mDestructionObjectName.mUID == -1 )
        break;
    }
    UFG::qReflectHandleBase::~qReflectHandleBase(&v16);
    v4 = v6;
  }
  v12 = *(_QWORD *)&v4[1].mChanged;
  if ( v12 )
    v13 = *(float *)(v12 + 268);
  else
    v13 = *(float *)&FLOAT_1_0;
  v14 = CompareFloat((UFG::InEqualityOperator)v3->mInEqualityOperator.mValue, v3->mDamageThreshold, v13);
  UFG::qReflectHandleBase::~qReflectHandleBase(&v16);
  return v14;
}

// File Line: 76
// RVA: 0x148ACD0
__int64 dynamic_initializer_for__DestructionFractureCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("DestructionFractureCondition", 0xFFFFFFFF);
  DestructionFractureCondition::sClassNameUID = result;
  return result;
}

// File Line: 82
// RVA: 0x276CE0
void __fastcall DestructionFractureCondition::DestructionFractureCondition(DestructionFractureCondition *this)
{
  DestructionFractureCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&DestructionFractureCondition::`vftable;
  v1->mFractureObjectName = UFG::gNullQSymbolUC;
}

// File Line: 86
// RVA: 0x2814F0
char __fastcall DestructionFractureCondition::Match(DestructionFractureCondition *this, ActionContext *context)
{
  ActionContext *v2; // rsi
  DestructionFractureCondition *v3; // rbp
  UFG::TransformNodeComponent *v4; // rbx
  UFG::TransformNodeComponent *v5; // rax
  unsigned int v6; // edx
  UFG::TransformNodeComponent *v7; // rdi
  bool v8; // zf
  UFG::StateMachineComponent *v9; // rcx

  v2 = context;
  v3 = this;
  v4 = UFG::SimObject::GetComponentOfType(
         context->mSimObject.m_pPointer,
         UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
         0,
         0i64);
  if ( !v4 )
    return 0;
  while ( 1 )
  {
    v5 = UFG::SimObject::GetComponentOfType(
           v2->mSimObject.m_pPointer,
           UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
           0,
           (UFG::SimComponent *)&v4->vfptr);
    v6 = v3->mFractureObjectName.mUID;
    v7 = v5;
    if ( v6 == -1 )
    {
      v8 = ((LODWORD(v4->mWorldVelocity.z) >> 5) & 1) == 0;
      goto LABEL_6;
    }
    v9 = *(UFG::StateMachineComponent **)&v4[1].mChanged;
    if ( v9 )
      break;
LABEL_7:
    v4 = v7;
    if ( !v7 )
      return 0;
  }
  v8 = UFG::StateMachineComponent::IsElementInFractureList(v9, v6) == 0;
LABEL_6:
  if ( v8 )
    goto LABEL_7;
  return 1;
}

