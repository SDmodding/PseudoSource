// File Line: 14
// RVA: 0xA27180
void __fastcall UFG::UIScreenInvoke::Invoke(UFG::UIScreenInvoke *this, Scaleform::GFx::Movie *movie)
{
  if ( movie )
  {
    if ( this->command.mLength )
      Scaleform::GFx::Movie::Invoke(movie, this->command.mData, 0i64, 0i64, 0);
  }
}

// File Line: 26
// RVA: 0xA272A0
void __fastcall UFG::UIScreenInvokeValueArgs::Invoke(UFG::UIScreenInvokeValueArgs *this, Scaleform::GFx::Movie *movie)
{
  Scaleform::GFx::Movie *v2; // r10
  Scaleform::GFx::Value *v3; // r9
  char *v4; // rdx

  v2 = movie;
  if ( movie && this->command.mLength )
  {
    v3 = this->args;
    v4 = this->command.mData;
    if ( v3 )
      Scaleform::GFx::Movie::Invoke(v2, v4, 0i64, v3, this->numArgs);
    else
      Scaleform::GFx::Movie::Invoke(v2, v4, 0i64, 0i64, 0);
  }
}

// File Line: 45
// RVA: 0xA271C0
void __fastcall UFG::UIScreenInvokeStringArgs::Invoke(UFG::UIScreenInvokeStringArgs *this, Scaleform::GFx::Movie *movie)
{
  Scaleform::GFx::Movie *v2; // rdi
  UFG::UIScreenInvokeStringArgs *v3; // rbx
  char *v4; // rsi
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h]

  if ( movie )
  {
    v2 = movie;
    v3 = this;
    if ( this->command.mLength )
    {
      pargs.pObjectInterface = 0i64;
      pargs.Type = 0;
      if ( this->numArgs > 0 )
      {
        v4 = this->args.mData;
        if ( ((unsigned int)pargs.Type >> 6) & 1 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
            pargs.pObjectInterface,
            &pargs,
            *(_QWORD *)&pargs.mValue.NValue);
          pargs.pObjectInterface = 0i64;
        }
        pargs.Type = 6;
        *(_QWORD *)&pargs.mValue.NValue = v4;
      }
      Scaleform::GFx::Movie::Invoke(v2, v3->command.mData, 0i64, &pargs, v3->numArgs);
      if ( ((unsigned int)pargs.Type >> 6) & 1 )
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
          pargs.pObjectInterface,
          &pargs,
          *(_QWORD *)&pargs.mValue.NValue);
    }
  }
}

// File Line: 63
// RVA: 0xA24760
void __fastcall UFG::UIScreenInvokeQueue::Add(UFG::UIScreenInvokeQueue *this, UFG::UIScreenInvoke *cmd)
{
  UFG::qNode<UFG::UIScreenInvoke,UFG::UIScreenInvoke> *v2; // rax
  UFG::qList<UFG::UIScreenInvoke,UFG::UIScreenInvoke,1,0> *v3; // r8
  UFG::qNode<UFG::UIScreenInvoke,UFG::UIScreenInvoke> *v4; // rcx

  if ( cmd )
  {
    v2 = this->mCommandQueue.mNode.mPrev;
    v3 = &this->mCommandQueue;
    v4 = (UFG::qNode<UFG::UIScreenInvoke,UFG::UIScreenInvoke> *)&cmd->mPrev;
    v2->mNext = (UFG::qNode<UFG::UIScreenInvoke,UFG::UIScreenInvoke> *)&cmd->mPrev;
    v4->mPrev = v2;
    v4->mNext = &v3->mNode;
    v3->mNode.mPrev = (UFG::qNode<UFG::UIScreenInvoke,UFG::UIScreenInvoke> *)&cmd->mPrev;
  }
}

// File Line: 72
// RVA: 0xA28880
void __fastcall UFG::UIScreenInvokeQueue::Update(UFG::UIScreenInvokeQueue *this, UFG::UIScreen *screen)
{
  UFG::UIScreenRenderable *v2; // rdi
  Scaleform::GFx::Movie *v3; // rdi
  UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *v4; // rbp
  int *v5; // rsi
  UFG::UIScreenInvokeQueue *v6; // rbx

  if ( screen )
  {
    v2 = screen->mRenderable;
    if ( v2 )
    {
      v3 = v2->m_movie.pObject;
      if ( v3 )
      {
        v4 = (UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)&this->mCommandQueue;
        if ( (int *)&this->mCommandQueue.mNode.mNext[-1].mNext != &this->mNumCommandsPerFrame )
        {
          v5 = &this->mNumCommandsPerFrame;
          v6 = (UFG::UIScreenInvokeQueue *)&this->mCommandQueue.mNode.mNext[-1].mNext;
          if ( v6 != (UFG::UIScreenInvokeQueue *)&this->mNumCommandsPerFrame )
          {
            do
            {
              if ( v6 )
                v6->vfptr[1].__vecDelDtor(v6, (unsigned int)v3);
              v6 = (UFG::UIScreenInvokeQueue *)&v6->mCommandQueue.mNode.mPrev[-1].mNext;
            }
            while ( v6 != (UFG::UIScreenInvokeQueue *)v5 );
          }
          UFG::qList<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption,1,0>::DeleteNodes(v4);
        }
      }
    }
  }
}

