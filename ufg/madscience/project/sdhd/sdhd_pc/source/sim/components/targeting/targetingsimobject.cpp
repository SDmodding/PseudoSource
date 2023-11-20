// File Line: 22
// RVA: 0x52F300
UFG::SimObject *__fastcall UFG::TargetingSimObject::GetOwner(UFG::TargetingSimObject *this)
{
  UFG::SimObject *result; // rax

  result = (UFG::SimObject *)this->m_pTSBC;
  if ( result )
    result = (UFG::SimObject *)result->mNode.mParent;
  return result;
}

// File Line: 29
// RVA: 0x54EB60
void __fastcall UFG::TargetingSimObject::SetTarget(UFG::TargetingSimObject *this, UFG::SimObject *pNewTarget)
{
  UFG::SimObject *v2; // rbx
  UFG::TargetingSimObject *v3; // rdi
  UFG::qNode<UFG::TargetingSimObject,UFG::TargetingSimObject> *v4; // r8
  UFG::qNode<UFG::TargetingSimObject,UFG::TargetingSimObject> *v5; // rax
  unsigned __int16 v6; // cx
  UFG::SimComponent *v7; // rax
  unsigned int v8; // er8
  unsigned int v9; // er9
  UFG::SimComponentHolder *v10; // rdx
  unsigned int v11; // er8
  unsigned int v12; // er9
  UFG::qNode<UFG::TargetingSimObject,UFG::TargetingSimObject> *v13; // rcx
  UFG::qNode<UFG::TargetingSimObject,UFG::TargetingSimObject> *v14; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v15; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v16; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v17; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v18; // rax

  v2 = pNewTarget;
  v3 = this;
  if ( pNewTarget == this->m_pTarget.m_pPointer )
    return;
  v4 = this->mPrev;
  v5 = this->mNext;
  v4->mNext = v5;
  v5->mPrev = v4;
  this->mPrev = (UFG::qNode<UFG::TargetingSimObject,UFG::TargetingSimObject> *)&this->mPrev;
  this->mNext = (UFG::qNode<UFG::TargetingSimObject,UFG::TargetingSimObject> *)&this->mPrev;
  if ( pNewTarget )
  {
    v6 = pNewTarget->m_Flags;
    if ( (v6 >> 14) & 1 )
    {
      v7 = pNewTarget->m_Components.p[20].m_pComponent;
      goto LABEL_23;
    }
    if ( (v6 & 0x8000u) != 0 )
    {
      v7 = pNewTarget->m_Components.p[20].m_pComponent;
      goto LABEL_23;
    }
    if ( (v6 >> 13) & 1 )
    {
      v8 = (unsigned int)pNewTarget[1].vfptr;
      v9 = pNewTarget->m_Components.size;
      if ( v8 < v9 )
      {
        v10 = &pNewTarget->m_Components.p[v8];
        while ( (v10->m_TypeUID & 0xFE000000) != (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
             || UFG::TargetingSystemBaseComponent::_TypeUID & ~v10->m_TypeUID & 0x1FFFFFF )
        {
          ++v8;
          ++v10;
          if ( v8 >= v9 )
            goto LABEL_13;
        }
LABEL_14:
        v7 = v10->m_pComponent;
        goto LABEL_23;
      }
    }
    else
    {
      if ( !((v6 >> 12) & 1) )
      {
        v7 = UFG::SimObject::GetComponentOfType(pNewTarget, UFG::TargetingSystemBaseComponent::_TypeUID);
LABEL_23:
        if ( v7 )
        {
          v13 = (UFG::qNode<UFG::TargetingSimObject,UFG::TargetingSimObject> *)&v7[1].m_pSimObject;
          v14 = (UFG::qNode<UFG::TargetingSimObject,UFG::TargetingSimObject> *)v7[1].m_pSimObject;
          v14->mNext = (UFG::qNode<UFG::TargetingSimObject,UFG::TargetingSimObject> *)&v3->mPrev;
          v3->mPrev = v14;
          v3->mNext = v13;
          v13->mPrev = (UFG::qNode<UFG::TargetingSimObject,UFG::TargetingSimObject> *)&v3->mPrev;
        }
        goto LABEL_25;
      }
      v11 = (unsigned int)pNewTarget[1].vfptr;
      v12 = pNewTarget->m_Components.size;
      if ( v11 < v12 )
      {
        v10 = &pNewTarget->m_Components.p[v11];
        while ( (v10->m_TypeUID & 0xFE000000) != (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
             || UFG::TargetingSystemBaseComponent::_TypeUID & ~v10->m_TypeUID & 0x1FFFFFF )
        {
          ++v11;
          ++v10;
          if ( v11 >= v12 )
          {
            v7 = 0i64;
            goto LABEL_23;
          }
        }
        goto LABEL_14;
      }
    }
LABEL_13:
    v7 = 0i64;
    goto LABEL_23;
  }
LABEL_25:
  v15 = &v3->m_pTarget;
  if ( v3->m_pTarget.m_pPointer )
  {
    v16 = v15->mPrev;
    v17 = v3->m_pTarget.mNext;
    v16->mNext = v17;
    v17->mPrev = v16;
    v15->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v15->mPrev;
    v3->m_pTarget.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v3->m_pTarget.mPrev;
  }
  v3->m_pTarget.m_pPointer = v2;
  if ( v2 )
  {
    v18 = v2->m_SafePointerList.mNode.mPrev;
    v18->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v15->mPrev;
    v15->mPrev = v18;
    v3->m_pTarget.mNext = &v2->m_SafePointerList.mNode;
    v2->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v15->mPrev;
  }
}

// File Line: 72
// RVA: 0x54D970
void __fastcall UFG::TargetingSimObject::SetLock(UFG::TargetingSimObject *this, bool bLock)
{
  if ( this->m_bLock != bLock )
    this->m_bLock = bLock;
}

