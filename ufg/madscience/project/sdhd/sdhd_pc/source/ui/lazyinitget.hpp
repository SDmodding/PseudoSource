// File Line: 27
// RVA: 0x5C8D10
void __fastcall UFG::LazyInitGet<UFG::UIFXManager>::~LazyInitGet<UFG::UIFXManager>(UFG::LazyInitGet<UFG::UIFXManager> *this)
{
  UFG::UIFXManager *v1; // rax

  v1 = UFG::LazyInitGet<UFG::UIFXManager>::m_instance;
  if ( UFG::LazyInitGet<UFG::UIFXManager>::m_instance == (UFG::UIFXManager *)this )
    v1 = 0i64;
  UFG::LazyInitGet<UFG::UIFXManager>::m_instance = v1;
}

// File Line: 32
// RVA: 0x620710
UFG::UIFlowInGame *__fastcall UFG::LazyInitGet<UFG::UIFlowInGame>::get()
{
  UFG::UIFlowInGame *result; // rax

  result = UFG::LazyInitGet<UFG::UIFlowInGame>::m_instance;
  if ( !UFG::LazyInitGet<UFG::UIFlowInGame>::m_instance )
  {
    result = (UFG::UIFlowInGame *)UFG::qMemoryPool::Allocate(
                                    &gScaleformMemoryPool,
                                    (unsigned int)((_DWORD)UFG::LazyInitGet<UFG::UIFlowInGame>::m_instance + 40),
                                    "UIFlow",
                                    0i64,
                                    1u);
    if ( result )
    {
      result->vfptr = (UFG::UIFlowVtbl *)&UFG::UIFlow::`vftable';
      result->m_screen_id = -1;
      result->m_child_flow = 0i64;
      *(_QWORD *)&result->m_state = 0i64;
      result->vfptr = (UFG::UIFlowVtbl *)&UFG::UIFlowInGame::`vftable';
    }
    else
    {
      result = 0i64;
    }
    UFG::LazyInitGet<UFG::UIFlowInGame>::m_instance = result;
  }
  return result;
}

