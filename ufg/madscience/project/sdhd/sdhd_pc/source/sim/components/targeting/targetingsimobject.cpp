// File Line: 22
// RVA: 0x52F300
UFG::qBaseNodeRB *__fastcall UFG::TargetingSimObject::GetOwner(UFG::TargetingSimObject *this)
{
  UFG::qBaseNodeRB *result; // rax

  result = (UFG::qBaseNodeRB *)this->m_pTSBC;
  if ( result )
    return result[1].mChild[0];
  return result;
}

// File Line: 29
// RVA: 0x54EB60
void __fastcall UFG::TargetingSimObject::SetTarget(UFG::TargetingSimObject *this, UFG::SimObject *pNewTarget)
{
  UFG::qNode<UFG::TargetingSimObject,UFG::TargetingSimObject> *mPrev; // r8
  UFG::qNode<UFG::TargetingSimObject,UFG::TargetingSimObject> *mNext; // rax
  signed __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // rax
  unsigned int vfptr; // r8d
  unsigned int size; // r9d
  UFG::SimComponentHolder *v10; // rdx
  unsigned int v11; // r8d
  unsigned int v12; // r9d
  UFG::qNode<UFG::TargetingSimObject,UFG::TargetingSimObject> *p_m_pSimObject; // rcx
  UFG::qNode<UFG::TargetingSimObject,UFG::TargetingSimObject> *m_pSimObject; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_m_pTarget; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v16; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v17; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v18; // rax

  if ( pNewTarget == this->m_pTarget.m_pPointer )
    return;
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = this;
  this->mNext = this;
  if ( pNewTarget )
  {
    m_Flags = pNewTarget->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = pNewTarget->m_Components.p[20].m_pComponent;
      goto LABEL_23;
    }
    if ( m_Flags < 0 )
    {
      m_pComponent = pNewTarget->m_Components.p[20].m_pComponent;
      goto LABEL_23;
    }
    if ( (m_Flags & 0x2000) != 0 )
    {
      vfptr = (unsigned int)pNewTarget[1].vfptr;
      size = pNewTarget->m_Components.size;
      if ( vfptr < size )
      {
        v10 = &pNewTarget->m_Components.p[vfptr];
        while ( (v10->m_TypeUID & 0xFE000000) != (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
             || (UFG::TargetingSystemBaseComponent::_TypeUID & ~v10->m_TypeUID & 0x1FFFFFF) != 0 )
        {
          ++vfptr;
          ++v10;
          if ( vfptr >= size )
            goto LABEL_13;
        }
LABEL_14:
        m_pComponent = v10->m_pComponent;
        goto LABEL_23;
      }
    }
    else
    {
      if ( (m_Flags & 0x1000) == 0 )
      {
        m_pComponent = UFG::SimObject::GetComponentOfType(pNewTarget, UFG::TargetingSystemBaseComponent::_TypeUID);
LABEL_23:
        if ( m_pComponent )
        {
          p_m_pSimObject = (UFG::qNode<UFG::TargetingSimObject,UFG::TargetingSimObject> *)&m_pComponent[1].m_pSimObject;
          m_pSimObject = (UFG::qNode<UFG::TargetingSimObject,UFG::TargetingSimObject> *)m_pComponent[1].m_pSimObject;
          m_pSimObject->mNext = this;
          this->mPrev = m_pSimObject;
          this->mNext = p_m_pSimObject;
          p_m_pSimObject->mPrev = this;
        }
        goto LABEL_25;
      }
      v11 = (unsigned int)pNewTarget[1].vfptr;
      v12 = pNewTarget->m_Components.size;
      if ( v11 < v12 )
      {
        v10 = &pNewTarget->m_Components.p[v11];
        while ( (v10->m_TypeUID & 0xFE000000) != (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
             || (UFG::TargetingSystemBaseComponent::_TypeUID & ~v10->m_TypeUID & 0x1FFFFFF) != 0 )
        {
          ++v11;
          ++v10;
          if ( v11 >= v12 )
          {
            m_pComponent = 0i64;
            goto LABEL_23;
          }
        }
        goto LABEL_14;
      }
    }
LABEL_13:
    m_pComponent = 0i64;
    goto LABEL_23;
  }
LABEL_25:
  p_m_pTarget = &this->m_pTarget;
  if ( this->m_pTarget.m_pPointer )
  {
    v16 = p_m_pTarget->mPrev;
    v17 = this->m_pTarget.mNext;
    v16->mNext = v17;
    v17->mPrev = v16;
    p_m_pTarget->mPrev = p_m_pTarget;
    this->m_pTarget.mNext = &this->m_pTarget;
  }
  this->m_pTarget.m_pPointer = pNewTarget;
  if ( pNewTarget )
  {
    v18 = pNewTarget->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
    v18->mNext = p_m_pTarget;
    p_m_pTarget->mPrev = v18;
    this->m_pTarget.mNext = &pNewTarget->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
    pNewTarget->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = p_m_pTarget;
  }
}

// File Line: 72
// RVA: 0x54D970
void __fastcall UFG::TargetingSimObject::SetLock(UFG::TargetingSimObject *this, bool bLock)
{
  if ( this->m_bLock != bLock )
    this->m_bLock = bLock;
}

