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
  Scaleform::GFx::Value *args; // r9
  char *mData; // rdx

  if ( movie && this->command.mLength )
  {
    args = this->args;
    mData = this->command.mData;
    if ( args )
      Scaleform::GFx::Movie::Invoke(movie, mData, 0i64, args, this->numArgs);
    else
      Scaleform::GFx::Movie::Invoke(movie, mData, 0i64, 0i64, 0);
  }
}

// File Line: 45
// RVA: 0xA271C0
void __fastcall UFG::UIScreenInvokeStringArgs::Invoke(
        UFG::UIScreenInvokeStringArgs *this,
        Scaleform::GFx::Movie *movie)
{
  char *mData; // rsi
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h] BYREF

  if ( movie && this->command.mLength )
  {
    pargs.pObjectInterface = 0i64;
    pargs.Type = VT_Undefined;
    if ( this->numArgs > 0 )
    {
      mData = this->args.mData;
      pargs.Type = VT_String;
      pargs.mValue.pString = mData;
    }
    Scaleform::GFx::Movie::Invoke(movie, this->command.mData, 0i64, &pargs, this->numArgs);
    if ( (pargs.Type & 0x40) != 0 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        pargs.mValue);
  }
}

// File Line: 63
// RVA: 0xA24760
void __fastcall UFG::UIScreenInvokeQueue::Add(UFG::UIScreenInvokeQueue *this, UFG::UIScreenInvoke *cmd)
{
  UFG::qNode<UFG::UIScreenInvoke,UFG::UIScreenInvoke> *mPrev; // rax

  if ( cmd )
  {
    mPrev = this->mCommandQueue.mNode.mPrev;
    mPrev->mNext = &cmd->UFG::qNode<UFG::UIScreenInvoke,UFG::UIScreenInvoke>;
    cmd->mPrev = mPrev;
    cmd->mNext = &this->mCommandQueue.mNode;
    this->mCommandQueue.mNode.mPrev = &cmd->UFG::qNode<UFG::UIScreenInvoke,UFG::UIScreenInvoke>;
  }
}

// File Line: 72
// RVA: 0xA28880
void __fastcall UFG::UIScreenInvokeQueue::Update(UFG::UIScreenInvokeQueue *this, UFG::UIScreen *screen)
{
  UFG::UIScreenRenderable *mRenderable; // rdi
  Scaleform::GFx::Movie *pObject; // rdi
  UFG::qList<UFG::UIScreenInvoke,UFG::UIScreenInvoke,1,0> *p_mCommandQueue; // rbp
  int *p_mNumCommandsPerFrame; // rsi
  UFG::UIScreenInvokeQueue *p_mNext; // rbx

  if ( screen )
  {
    mRenderable = screen->mRenderable;
    if ( mRenderable )
    {
      pObject = mRenderable->m_movie.pObject;
      if ( pObject )
      {
        p_mCommandQueue = &this->mCommandQueue;
        if ( (int *)&this->mCommandQueue.mNode.mNext[-1].mNext != &this->mNumCommandsPerFrame )
        {
          p_mNumCommandsPerFrame = &this->mNumCommandsPerFrame;
          p_mNext = (UFG::UIScreenInvokeQueue *)&this->mCommandQueue.mNode.mNext[-1].mNext;
          if ( p_mNext != (UFG::UIScreenInvokeQueue *)&this->mNumCommandsPerFrame )
          {
            do
            {
              if ( p_mNext )
                p_mNext->vfptr[1].__vecDelDtor(p_mNext, (unsigned int)pObject);
              p_mNext = (UFG::UIScreenInvokeQueue *)&p_mNext->mCommandQueue.mNode.mPrev[-1].mNext;
            }
            while ( p_mNext != (UFG::UIScreenInvokeQueue *)p_mNumCommandsPerFrame );
          }
          UFG::qList<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption,1,0>::DeleteNodes((UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)p_mCommandQueue);
        }
      }
    }
  }
}

