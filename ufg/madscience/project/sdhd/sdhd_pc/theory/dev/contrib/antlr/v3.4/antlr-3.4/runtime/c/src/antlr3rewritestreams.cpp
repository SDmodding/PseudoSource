// File Line: 69
// RVA: 0x25F270
void __fastcall freeRS(ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *stream)
{
  ANTLR3_VECTOR_struct *elements; // rdx
  __int64 v3; // rcx
  ANTLR3_VECTOR_struct *rStreams; // rcx

  elements = stream->elements;
  if ( elements )
  {
    if ( elements->factoryMade == 1 )
    {
      v3 = *(_QWORD *)(*((_QWORD *)stream->adaptor->super + 44) + 328i64);
      (*(void (__fastcall **)(__int64))(v3 + 392))(v3);
      stream->elements = 0i64;
    }
    else
    {
      elements->clear(stream->elements);
      stream->freeElements = 1;
    }
  }
  else
  {
    stream->freeElements = 0;
  }
  rStreams = stream->rec->state->rStreams;
  rStreams->add(rStreams, stream, (void (__fastcall *)(void *))expungeRS);
}

// File Line: 112
// RVA: 0x25F180
void __fastcall freeNodeRS(ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *stream)
{
  ANTLR3_VECTOR_struct *elements; // rax
  unsigned int v3; // edi
  ANTLR3_VECTOR_ELEMENT_struct *v4; // rcx
  void (__fastcall **element)(void *); // rax
  ANTLR3_VECTOR_struct *v6; // rdx
  __int64 v7; // rcx
  void (__fastcall **singleElement)(void *); // rax
  ANTLR3_VECTOR_struct *rStreams; // rcx

  elements = stream->elements;
  if ( elements )
  {
    v3 = 1;
    if ( elements->count )
    {
      do
      {
        v4 = stream->elements->elements;
        element = (void (__fastcall **)(void *))v4[v3 - 1].element;
        if ( element )
          element[24](v4[v3 - 1].element);
        ++v3;
      }
      while ( v3 <= stream->elements->count );
    }
    v6 = stream->elements;
    if ( v6->factoryMade == 1 )
    {
      v7 = *(_QWORD *)(*((_QWORD *)stream->adaptor->super + 44) + 328i64);
      (*(void (__fastcall **)(__int64))(v7 + 392))(v7);
      stream->elements = 0i64;
    }
    else
    {
      v6->clear(stream->elements);
      stream->freeElements = 1;
    }
  }
  else
  {
    singleElement = (void (__fastcall **)(void *))stream->singleElement;
    if ( singleElement )
      singleElement[24](stream->singleElement);
    stream->singleElement = 0i64;
    stream->freeElements = 0;
  }
  rStreams = stream->rec->state->rStreams;
  rStreams->add(rStreams, stream, (void (__fastcall *)(void *))expungeRS);
}

// File Line: 178
// RVA: 0x25F150
void __fastcall expungeRS(ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *stream)
{
  ANTLR3_VECTOR_struct *elements; // rax

  if ( stream->freeElements == 1 )
  {
    elements = stream->elements;
    if ( elements )
      elements->free(stream->elements);
  }
  antlrFree((char *)stream);
}

// File Line: 191
// RVA: 0x25F020
UFG::allocator::free_link *__fastcall antlr3RewriteRuleElementStreamNewAE(
        UFG::allocator::free_link *adaptor,
        UFG::allocator::free_link *rec,
        UFG::allocator::free_link *description)
{
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *mNext; // rax
  ANTLR3_VECTOR_struct *rStreams; // r9
  unsigned int count; // edx
  UFG::allocator::free_link *result; // rax

  mNext = (ANTLR3_RECOGNIZER_SHARED_STATE_struct *)rec[2].mNext;
  rStreams = mNext->rStreams;
  count = rStreams->count;
  if ( count )
  {
    result = (UFG::allocator::free_link *)rStreams->remove(mNext->rStreams, count - 1);
  }
  else
  {
    result = antlrMalloc(0xA8ui64);
    if ( !result )
      return result;
    result[2].mNext = 0i64;
    LOBYTE(result[3].mNext) = 0;
  }
  result[7].mNext = rec;
  result[8].mNext = (UFG::allocator::free_link *)reset_2;
  result[5].mNext = adaptor;
  result[9].mNext = (UFG::allocator::free_link *)add;
  result[10].mNext = (UFG::allocator::free_link *)next;
  result[1].mNext = 0i64;
  result[11].mNext = (UFG::allocator::free_link *)nextTree;
  LODWORD(result->mNext) = 0;
  result[17].mNext = (UFG::allocator::free_link *)nextNode;
  LOBYTE(result[6].mNext) = 0;
  result[12].mNext = (UFG::allocator::free_link *)nextToken_0;
  result[4].mNext = description;
  result[13].mNext = (UFG::allocator::free_link *)next;
  result[16].mNext = (UFG::allocator::free_link *)hasNext;
  result[18].mNext = (UFG::allocator::free_link *)size_0;
  result[19].mNext = (UFG::allocator::free_link *)getDescription;
  result[15].mNext = (UFG::allocator::free_link *)UFG::qPropertyList::operator new;
  result[20].mNext = (UFG::allocator::free_link *)freeRS;
  return result;
}

// File Line: 313
// RVA: 0x25F750
UFG::allocator::free_link *__fastcall antlr3RewriteRuleTOKENStreamNewAE(
        UFG::allocator::free_link *adaptor,
        UFG::allocator::free_link *rec,
        UFG::allocator::free_link *description)
{
  UFG::allocator::free_link *result; // rax

  result = antlr3RewriteRuleElementStreamNewAE(adaptor, rec, description);
  if ( result )
  {
    result[14].mNext = (UFG::allocator::free_link *)TargetVisibleInAIDataCondition::CreateClone;
    result[17].mNext = (UFG::allocator::free_link *)nextNodeToken;
  }
  return result;
}

// File Line: 337
// RVA: 0x25F790
UFG::allocator::free_link *__fastcall antlr3RewriteRuleTOKENStreamNewAEE(
        UFG::allocator::free_link *adaptor,
        UFG::allocator::free_link *rec,
        UFG::allocator::free_link *description,
        void *oneElement)
{
  UFG::allocator::free_link *v5; // rax
  UFG::allocator::free_link *v6; // rbx

  v5 = antlr3RewriteRuleElementStreamNewAE(adaptor, rec, description);
  v6 = v5;
  if ( v5 && oneElement )
    ((void (__fastcall *)(UFG::allocator::free_link *, void *, _QWORD))v5[9].mNext)(v5, oneElement, 0i64);
  v6[14].mNext = (UFG::allocator::free_link *)TargetVisibleInAIDataCondition::CreateClone;
  v6[17].mNext = (UFG::allocator::free_link *)nextNodeToken;
  return v6;
}

// File Line: 356
// RVA: 0x25F7F0
UFG::allocator::free_link *__fastcall antlr3RewriteRuleTOKENStreamNewAEV(
        UFG::allocator::free_link *adaptor,
        UFG::allocator::free_link *rec,
        UFG::allocator::free_link *description,
        UFG::allocator::free_link *vector)
{
  UFG::allocator::free_link *v5; // rax
  UFG::allocator::free_link *v6; // rbx
  UFG::allocator::free_link *mNext; // rax

  v5 = antlr3RewriteRuleElementStreamNewAE(adaptor, rec, description);
  v6 = v5;
  if ( v5 )
  {
    mNext = v5[2].mNext;
    if ( mNext && !LOBYTE(mNext[34].mNext) && LOBYTE(v6[3].mNext) == 1 )
      ((void (__fastcall *)(UFG::allocator::free_link *))mNext[35].mNext)(mNext);
    v6[2].mNext = vector;
    LOBYTE(v6[3].mNext) = 0;
  }
  v6[14].mNext = (UFG::allocator::free_link *)TargetVisibleInAIDataCondition::CreateClone;
  v6[17].mNext = (UFG::allocator::free_link *)nextNodeToken;
  return v6;
}

// File Line: 377
// RVA: 0x25F610
UFG::allocator::free_link *__fastcall antlr3RewriteRuleSubtreeStreamNewAE(
        UFG::allocator::free_link *adaptor,
        UFG::allocator::free_link *rec,
        UFG::allocator::free_link *description)
{
  UFG::allocator::free_link *result; // rax

  result = antlr3RewriteRuleElementStreamNewAE(adaptor, rec, description);
  if ( result )
  {
    result[14].mNext = (UFG::allocator::free_link *)toTreeNode;
    result[17].mNext = (UFG::allocator::free_link *)nextNode;
    result[20].mNext = (UFG::allocator::free_link *)freeNodeRS;
  }
  return result;
}

// File Line: 399
// RVA: 0x25F650
ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *__fastcall antlr3RewriteRuleSubtreeStreamNewAEE(
        UFG::allocator::free_link *adaptor,
        UFG::allocator::free_link *rec,
        UFG::allocator::free_link *description,
        void *oneElement)
{
  ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *result; // rax
  ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *v6; // rbx

  result = (ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *)antlr3RewriteRuleElementStreamNewAE(adaptor, rec, description);
  v6 = result;
  if ( result )
  {
    if ( oneElement )
      result->add(result, oneElement, 0i64);
    v6->dup = (void *(__fastcall *)(ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *, void *))toTreeNode;
    v6->nextNode = nextNode;
    v6->free = freeNodeRS;
    return v6;
  }
  return result;
}

// File Line: 422
// RVA: 0x25F6C0
UFG::allocator::free_link *__fastcall antlr3RewriteRuleSubtreeStreamNewAEV(
        UFG::allocator::free_link *adaptor,
        UFG::allocator::free_link *rec,
        UFG::allocator::free_link *description,
        ANTLR3_VECTOR_struct *vector)
{
  UFG::allocator::free_link *result; // rax
  ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *v6; // rbx
  ANTLR3_VECTOR_struct *mNext; // rax

  result = antlr3RewriteRuleElementStreamNewAE(adaptor, rec, description);
  v6 = (ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *)result;
  if ( result )
  {
    mNext = (ANTLR3_VECTOR_struct *)result[2].mNext;
    if ( mNext && !mNext->factoryMade && v6->freeElements == 1 )
      mNext->free(mNext);
    v6->elements = vector;
    v6->freeElements = 0;
    v6->dup = (void *(__fastcall *)(ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *, void *))toTreeNode;
    v6->nextNode = nextNode;
    v6->free = freeNodeRS;
    return (UFG::allocator::free_link *)v6;
  }
  return result;
}

// File Line: 446
// RVA: 0x25F4C0
UFG::allocator::free_link *__fastcall antlr3RewriteRuleNODEStreamNewAE(
        UFG::allocator::free_link *adaptor,
        UFG::allocator::free_link *rec,
        UFG::allocator::free_link *description)
{
  UFG::allocator::free_link *result; // rax

  result = antlr3RewriteRuleElementStreamNewAE(adaptor, rec, description);
  if ( result )
  {
    result[14].mNext = (UFG::allocator::free_link *)TargetVisibleInAIDataCondition::CreateClone;
    result[15].mNext = (UFG::allocator::free_link *)toTreeNode;
    result[17].mNext = (UFG::allocator::free_link *)nextToken_0;
    result[20].mNext = (UFG::allocator::free_link *)freeNodeRS;
  }
  return result;
}

// File Line: 470
// RVA: 0x25F510
UFG::allocator::free_link *__fastcall antlr3RewriteRuleNODEStreamNewAEE(
        UFG::allocator::free_link *adaptor,
        UFG::allocator::free_link *rec,
        UFG::allocator::free_link *description,
        void *oneElement)
{
  UFG::allocator::free_link *v5; // rax
  UFG::allocator::free_link *v6; // rbx

  v5 = antlr3RewriteRuleElementStreamNewAE(adaptor, rec, description);
  v6 = v5;
  if ( v5 && oneElement )
    ((void (__fastcall *)(UFG::allocator::free_link *, void *, _QWORD))v5[9].mNext)(v5, oneElement, 0i64);
  v6[14].mNext = (UFG::allocator::free_link *)TargetVisibleInAIDataCondition::CreateClone;
  v6[15].mNext = (UFG::allocator::free_link *)toTreeNode;
  v6[17].mNext = (UFG::allocator::free_link *)nextToken_0;
  v6[20].mNext = (UFG::allocator::free_link *)freeNodeRS;
  return v6;
}

// File Line: 489
// RVA: 0x25F580
UFG::allocator::free_link *__fastcall antlr3RewriteRuleNODEStreamNewAEV(
        UFG::allocator::free_link *adaptor,
        UFG::allocator::free_link *rec,
        UFG::allocator::free_link *description,
        UFG::allocator::free_link *vector)
{
  UFG::allocator::free_link *v5; // rax
  UFG::allocator::free_link *v6; // rbx
  UFG::allocator::free_link *mNext; // rax

  v5 = antlr3RewriteRuleElementStreamNewAE(adaptor, rec, description);
  v6 = v5;
  if ( v5 )
  {
    mNext = v5[2].mNext;
    if ( mNext && !LOBYTE(mNext[34].mNext) && LOBYTE(v6[3].mNext) == 1 )
      ((void (__fastcall *)(UFG::allocator::free_link *))mNext[35].mNext)(mNext);
    v6[2].mNext = vector;
    LOBYTE(v6[3].mNext) = 0;
  }
  v6[14].mNext = (UFG::allocator::free_link *)TargetVisibleInAIDataCondition::CreateClone;
  v6[15].mNext = (UFG::allocator::free_link *)toTreeNode;
  v6[17].mNext = (UFG::allocator::free_link *)nextToken_0;
  v6[20].mNext = (UFG::allocator::free_link *)freeNodeRS;
  return v6;
}

// File Line: 514
// RVA: 0x25F480
void __fastcall reset_2(ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *stream)
{
  stream->dirty = 1;
  stream->cursor = 0;
}

// File Line: 523
// RVA: 0x25EF50
void __fastcall add(ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *stream, void *el, void (__fastcall *freePtr)(void *))
{
  ANTLR3_VECTOR_struct *elements; // rax
  __int64 v7; // rcx
  ANTLR3_VECTOR_struct *v8; // rax

  if ( el )
  {
    elements = stream->elements;
    if ( elements && elements->count )
    {
      ((void (__fastcall *)(ANTLR3_VECTOR_struct *))elements->add)(stream->elements);
    }
    else if ( stream->singleElement )
    {
      if ( !elements )
      {
        v7 = *(_QWORD *)(*((_QWORD *)stream->adaptor->super + 44) + 328i64);
        v8 = (ANTLR3_VECTOR_struct *)(*(__int64 (__fastcall **)(__int64))(v7 + 384))(v7);
        stream->freeElements = 1;
        stream->elements = v8;
      }
      stream->elements->add(stream->elements, stream->singleElement, freePtr);
      stream->elements->add(stream->elements, el, freePtr);
      stream->singleElement = 0i64;
    }
    else
    {
      stream->singleElement = el;
    }
  }
}

// File Line: 572
// RVA: 0x25F430
ANTLR3_BASE_TREE_struct *__fastcall nextTree(ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *stream)
{
  unsigned int v2; // eax
  void *v4; // rax

  v2 = ((__int64 (*)(void))stream->size)();
  if ( !stream->dirty && (stream->cursor < v2 || v2 != 1) )
    return (ANTLR3_BASE_TREE_struct *)stream->_next(stream);
  v4 = stream->_next(stream);
  return (ANTLR3_BASE_TREE_struct *)stream->dup(stream, v4);
}

// File Line: 605
// RVA: 0x25F350
void *__fastcall next(ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *stream)
{
  unsigned int v2; // eax
  void *v3; // rax

  v2 = ((__int64 (*)(void))stream->size)();
  if ( stream->cursor < v2 || v2 != 1 )
    return stream->_next(stream);
  v3 = stream->_next(stream);
  return stream->dup(stream, v3);
}

// File Line: 629
// RVA: 0x25EED0
ANTLR3_BASE_TREE_struct *__fastcall next(ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *stream)
{
  unsigned int v2; // eax
  ANTLR3_BASE_TREE_struct *result; // rax
  void *singleElement; // rdx
  void *v5; // rax

  v2 = ((__int64 (*)(void))stream->size)();
  if ( !v2 )
    return 0i64;
  if ( stream->cursor < v2 )
  {
    if ( stream->singleElement )
    {
      singleElement = stream->singleElement;
      ++stream->cursor;
      return stream->toTree(stream, singleElement);
    }
    else
    {
      v5 = (void *)((__int64 (__fastcall *)(ANTLR3_VECTOR_struct *))stream->elements->get)(stream->elements);
      result = stream->toTree(stream, v5);
      ++stream->cursor;
    }
  }
  else
  {
    if ( v2 != 1 )
      return 0i64;
    return stream->toTree(stream, stream->singleElement);
  }
  return result;
}

// File Line: 694
// RVA: 0x25F4B0
ANTLR3_BASE_TREE_struct *__fastcall toTreeNode(ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *stream, void *element)
{
  return (ANTLR3_BASE_TREE_struct *)stream->adaptor->dupNode(stream->adaptor, element);
}

// File Line: 735
// RVA: 0x25F310
bool __fastcall hasNext(ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *stream)
{
  ANTLR3_VECTOR_struct *elements; // rax
  bool result; // al

  result = 1;
  if ( !stream->singleElement || stream->cursor )
  {
    elements = stream->elements;
    if ( !elements || stream->cursor >= elements->size(stream->elements) )
      return 0;
  }
  return result;
}

// File Line: 752
// RVA: 0x25F3F0
ANTLR3_BASE_TREE_struct *__fastcall nextNodeToken(ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *stream)
{
  ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor; // rbx
  __int64 v3; // rax

  adaptor = stream->adaptor;
  v3 = ((__int64 (*)(void))stream->_next)();
  return (ANTLR3_BASE_TREE_struct *)adaptor->create(stream->adaptor, (ANTLR3_COMMON_TOKEN_struct *)v3);
}

// File Line: 758
// RVA: 0x25F420
__int64 __fastcall nextToken_0(ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *stream)
{
  return ((__int64 (*)(void))stream->_next)();
}

// File Line: 773
// RVA: 0x25F390
ANTLR3_BASE_TREE_struct *__fastcall nextNode(ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *stream)
{
  void *v2; // rdi
  unsigned int v3; // eax

  v2 = (void *)((__int64 (*)(void))stream->_next)();
  v3 = stream->size(stream);
  if ( stream->dirty == 1 || stream->cursor > v3 && v3 == 1 )
    return (ANTLR3_BASE_TREE_struct *)stream->adaptor->dupNode(stream->adaptor, v2);
  else
    return (ANTLR3_BASE_TREE_struct *)v2;
}

// File Line: 796
// RVA: 0x25F490
__int64 __fastcall size_0(ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *stream)
{
  __int64 result; // rax
  ANTLR3_VECTOR_struct *elements; // rcx

  result = 0i64;
  if ( stream->singleElement )
    return 1i64;
  elements = stream->elements;
  if ( elements )
    return elements->count;
  return result;
}

// File Line: 821
// RVA: 0x25F2F0
void *__fastcall getDescription(ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *stream)
{
  if ( !stream->elementDescription )
    stream->elementDescription = "<unknown source>";
  return stream->elementDescription;
}

