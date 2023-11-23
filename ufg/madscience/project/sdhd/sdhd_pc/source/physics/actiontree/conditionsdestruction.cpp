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
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&DestructionDamageCondition::`vftable;
  this->mDamageThreshold = 0.0;
  this->mInEqualityOperator.mValue = 3;
  this->mDestructionObjectName = UFG::gNullQSymbolUC;
}

// File Line: 41
// RVA: 0x2813B0
char __fastcall DestructionDamageCondition::Match(DestructionDamageCondition *this, ActionContext *context)
{
  UFG::TransformNodeComponent *ComponentOfType; // rsi
  bool i; // zf
  UFG::TransformNodeComponent *v6; // rdi
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v7; // rcx
  const char *TypeName; // rax
  __int64 v9; // rdx
  unsigned int mUID; // ebx
  char *Name; // rax
  __int64 v12; // rax
  float v13; // xmm2_4
  char v14; // bl
  UFG::qReflectHandleBase v16; // [rsp+28h] [rbp-30h] BYREF

  ComponentOfType = UFG::SimObject::GetComponentOfType(
                      context->mSimObject.m_pPointer,
                      UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
                      0,
                      0i64);
  for ( i = ComponentOfType == 0i64; ; i = v6 == 0i64 )
  {
    if ( i )
      return 0;
    v6 = UFG::SimObject::GetComponentOfType(
           context->mSimObject.m_pPointer,
           UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
           0,
           ComponentOfType);
    UFG::qReflectHandleBase::qReflectHandleBase(&v16);
    TypeName = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v7);
    v16.mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
    v9 = *(_QWORD *)&ComponentOfType->mWorldTransform.v2.x;
    if ( v9 )
      UFG::qReflectHandleBase::operator=(&v16, (UFG::qReflectHandleBase *)(v9 + 224));
    if ( v16.mData )
    {
      mUID = this->mDestructionObjectName.mUID;
      Name = UFG::qReflectObject::GetName(v16.mData);
      if ( mUID == (unsigned int)UFG::qStringHashUpper32(Name, -1) || this->mDestructionObjectName.mUID == -1 )
        break;
    }
    UFG::qReflectHandleBase::~qReflectHandleBase(&v16);
    ComponentOfType = v6;
  }
  v12 = *(_QWORD *)&ComponentOfType[1].mChanged;
  if ( v12 )
    v13 = *(float *)(v12 + 268);
  else
    v13 = *(float *)&FLOAT_1_0;
  v14 = CompareFloat((UFG::InEqualityOperator)this->mInEqualityOperator.mValue, this->mDamageThreshold, v13);
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
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&DestructionFractureCondition::`vftable;
  this->mFractureObjectName = UFG::gNullQSymbolUC;
}

// File Line: 86
// RVA: 0x2814F0
char __fastcall DestructionFractureCondition::Match(DestructionFractureCondition *this, ActionContext *context)
{
  UFG::TransformNodeComponent *ComponentOfType; // rbx
  UFG::TransformNodeComponent *v5; // rax
  unsigned int mUID; // edx
  UFG::TransformNodeComponent *v7; // rdi
  bool v8; // zf
  UFG::StateMachineComponent *v9; // rcx

  ComponentOfType = UFG::SimObject::GetComponentOfType(
                      context->mSimObject.m_pPointer,
                      UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
                      0,
                      0i64);
  if ( !ComponentOfType )
    return 0;
  while ( 1 )
  {
    v5 = UFG::SimObject::GetComponentOfType(
           context->mSimObject.m_pPointer,
           UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
           0,
           ComponentOfType);
    mUID = this->mFractureObjectName.mUID;
    v7 = v5;
    if ( mUID == -1 )
    {
      v8 = (LODWORD(ComponentOfType->mWorldVelocity.z) & 0x20) == 0;
      goto LABEL_6;
    }
    v9 = *(UFG::StateMachineComponent **)&ComponentOfType[1].mChanged;
    if ( v9 )
      break;
LABEL_7:
    ComponentOfType = v7;
    if ( !v7 )
      return 0;
  }
  v8 = !UFG::StateMachineComponent::IsElementInFractureList(v9, mUID);
LABEL_6:
  if ( v8 )
    goto LABEL_7;
  return 1;
}

