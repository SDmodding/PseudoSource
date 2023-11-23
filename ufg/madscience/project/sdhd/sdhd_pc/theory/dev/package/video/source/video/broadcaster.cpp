// File Line: 13
// RVA: 0x1457700
__int64 dynamic_initializer_for__gVideoBroadcastMemoryPool__()
{
  UFG::qMemoryPool::qMemoryPool(&gVideoBroadcastMemoryPool);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gVideoBroadcastMemoryPool__);
}

// File Line: 38
// RVA: 0x81CB0
void __fastcall LoginCallback(__int64 result, _DWORD *userData)
{
  const char *v3; // rax
  int v4; // eax
  int v5; // eax
  const char *v6; // rax
  int v7; // eax

  if ( (int)result > 0 )
  {
    v3 = (const char *)TTV_ErrorToString(result);
    UFG::qPrintf("ERROR: twitch.tv - LoginCallback got failure: %s. Shutting down streaming...\n", v3);
    v4 = userData[468];
    *((_BYTE *)userData + 1877) = 1;
    if ( ((v4 - 10) & 0xFFFFFFFD) != 0 )
    {
      *((_BYTE *)userData + 1876) = 0;
      *((_BYTE *)userData + 80) = 0;
      if ( userData[468] )
      {
        userData[468] = 0;
        v7 = TTV_Shutdown();
        if ( v7 > 0 )
          TTV_ErrorToString((unsigned int)v7);
      }
    }
    else
    {
      v5 = TTV_Stop(StopCallback, userData);
      if ( v5 <= 0 )
      {
        userData[468] = 11;
      }
      else
      {
        v6 = (const char *)TTV_ErrorToString((unsigned int)v5);
        UFG::qPrintf("ERROR: twitch.tv - Error while stopping the stream: %s\n", v6);
      }
      *((_BYTE *)userData + 1878) = 1;
    }
  }
  else
  {
    userData[468] = 5;
  }
}

// File Line: 59
// RVA: 0x81C50
void __fastcall IngestListCallback(__int64 result, Broadcaster *userData)
{
  const char *v3; // rax

  if ( (int)result > 0 )
  {
    v3 = (const char *)TTV_ErrorToString(result);
    UFG::qPrintf("ERROR: twitch.tv - IngestListCallback got failure: %s\n", v3);
  }
  else if ( Broadcaster::FindIngestServer(userData) )
  {
    userData->mStreamState = eStreamState_FoundIngestServer;
  }
}

// File Line: 77
// RVA: 0x81D80
void __fastcall StartCallback(__int64 result, Broadcaster *userData)
{
  __int64 v3; // rax
  int v4; // eax
  const char *v5; // rax
  int v6; // eax

  if ( (int)result <= 0 )
  {
    Broadcaster::StreamStarted(userData);
  }
  else
  {
    v3 = TTV_ErrorToString(result);
    UFG::qPrintf(0i64, "ERROR: twitch.tv - Error while starting to stream: %s\n", v3);
    if ( ((userData->mStreamState - 10) & 0xFFFFFFFD) != 0 )
    {
      userData->mAuthTokenSavedThisSession = 0;
      userData->mAuthToken.data[0] = 0;
      if ( userData->mStreamState )
      {
        userData->mStreamState = eStreamState_Uninitialized;
        v6 = TTV_Shutdown();
        if ( v6 > 0 )
          TTV_ErrorToString((unsigned int)v6);
      }
    }
    else
    {
      v4 = TTV_Stop(StopCallback, userData);
      if ( v4 <= 0 )
      {
        userData->mStreamState = eStreamState_StoppingStream;
      }
      else
      {
        v5 = (const char *)TTV_ErrorToString((unsigned int)v4);
        UFG::qPrintf("ERROR: twitch.tv - Error while stopping the stream: %s\n", v5);
      }
      userData->mShutdownStreamingAfterStop = 1;
    }
  }
}

// File Line: 92
// RVA: 0x82240
void __fastcall StopCallback(__int64 result, Broadcaster *userData)
{
  const char *v2; // rax

  if ( (int)result <= 0 )
  {
    Broadcaster::StreamStopped(userData);
  }
  else
  {
    v2 = (const char *)TTV_ErrorToString(result);
    UFG::qPrintf("ERROR: twitch.tv - Error while stopping the stream: %s\n", v2);
  }
}

// File Line: 109
// RVA: 0x826D0
void __fastcall UserInfoDoneCallback(__int64 result, void *__formal)
{
  const char *v2; // rax

  if ( (int)result > 0 )
  {
    v2 = (const char *)TTV_ErrorToString(result);
    UFG::qPrintf("ERROR: twitch.tv - UserInfoDoneCallback got failure: %s\n", v2);
  }
}

// File Line: 121
// RVA: 0x82270
void __fastcall StreamInfoDoneCallback(__int64 result, void *__formal)
{
  const char *v2; // rax

  if ( (int)result > 0 && (_DWORD)result != 37 )
  {
    v2 = (const char *)TTV_ErrorToString(result);
    UFG::qPrintf("ERROR: twitch.tv - StreamInfoDoneCallback got failure: %s\n", v2);
  }
}

// File Line: 153
// RVA: 0x81B20
void __fastcall FrameUnlockCallback(char *_buffer, Broadcaster *userData)
{
  Broadcaster::FreeBuffer(userData, _buffer);
}

// File Line: 165
// RVA: 0x81850
void __fastcall Broadcaster::Broadcaster(Broadcaster *this)
{
  UFG::qString::qString(&this->mUserName);
  UFG::qString::qString(&this->mPassword);
  this->mAllFrameBuffers.p = 0i64;
  *(_QWORD *)&this->mAllFrameBuffers.size = 0i64;
  this->mFreeFrameBuffers.p = 0i64;
  *(_QWORD *)&this->mFreeFrameBuffers.size = 0i64;
  this->mStreamState = eStreamState_Uninitialized;
  *(_WORD *)&this->mAuthTokenSavedThisSession = 0;
  this->mShutdownStreamingAfterStop = 0;
}

// File Line: 222
// RVA: 0x81B30
void __fastcall Broadcaster::FreeBuffer(Broadcaster *this, UFG::qReflectInventoryBase *buffer)
{
  UFG::qArray<UFG::qReflectInventoryBase *,0> *p_mFreeFrameBuffers; // rdi
  __int64 size; // rsi
  unsigned int capacity; // edx
  unsigned int v6; // ebx
  unsigned int v7; // edx
  UFG::qReflectInventoryBase **p; // rax

  p_mFreeFrameBuffers = (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&this->mFreeFrameBuffers;
  size = this->mFreeFrameBuffers.size;
  capacity = this->mFreeFrameBuffers.capacity;
  v6 = size + 1;
  if ( (int)size + 1 > capacity )
  {
    if ( capacity )
      v7 = 2 * capacity;
    else
      v7 = 1;
    for ( ; v7 < v6; v7 *= 2 )
      ;
    if ( v7 <= 2 )
      v7 = 2;
    if ( v7 - v6 > 0x10000 )
      v7 = size + 65537;
    UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(p_mFreeFrameBuffers, v7, "qArray.Add");
  }
  p = p_mFreeFrameBuffers->p;
  p_mFreeFrameBuffers->size = v6;
  p[size] = buffer;
}

// File Line: 229
// RVA: 0x822A0
void __fastcall Broadcaster::StreamStarted(Broadcaster *this)
{
  _FILETIME SystemTime; // rax
  float mLength; // xmm0_4
  int v4; // eax
  __int64 v5; // rax
  int v6; // eax
  const char *v7; // rax
  int v8; // eax
  int mYear; // [rsp+20h] [rbp-68h]
  int mHour; // [rsp+28h] [rbp-60h]
  int mMinute; // [rsp+30h] [rbp-58h]
  int mSecond; // [rsp+38h] [rbp-50h]
  UFG::qDateTime date_time; // [rsp+48h] [rbp-40h] BYREF
  UFG::qString result; // [rsp+58h] [rbp-30h] BYREF

  this->mStreamTimeStartTicks = UFG::qGetTicks();
  SystemTime = UFG::qGetSystemTime();
  UFG::qConvertSystemTimeToDateTime(&date_time, *(_QWORD *)&SystemTime);
  mSecond = date_time.mSecond;
  mMinute = date_time.mMinute;
  mHour = date_time.mHour;
  mYear = date_time.mYear;
  UFG::qString::FormatEx(
    &result,
    "%02d/%02d/%04d, %02d:%02d:%02d",
    date_time.mDay,
    date_time.mMonth,
    mYear,
    mHour,
    mMinute,
    mSecond);
  this->mStreamInfoForSetting.size = 520i64;
  mLength = FLOAT_255_0;
  if ( (float)result.mLength <= 255.0 )
    mLength = (float)result.mLength;
  UFG::qMemCopy(this->mStreamInfoForSetting.streamTitle, result.mData, (int)mLength);
  UFG::qMemCopy(this->mStreamInfoForSetting.gameName, "UFG", 3u);
  v4 = TTV_SetStreamInfo(&this->mAuthToken, this->mChannelInfo.name, &this->mStreamInfoForSetting);
  if ( v4 <= 0 )
  {
    this->mStreamState = eStreamState_Streaming;
  }
  else
  {
    v5 = TTV_ErrorToString((unsigned int)v4);
    UFG::qPrintf(0i64, "ERROR: twitch.tv - Error while sending stream info: %s\n", v5);
    if ( ((this->mStreamState - 10) & 0xFFFFFFFD) != 0 )
    {
      this->mAuthTokenSavedThisSession = 0;
      this->mAuthToken.data[0] = 0;
      if ( this->mStreamState )
      {
        this->mStreamState = eStreamState_Uninitialized;
        v8 = TTV_Shutdown();
        if ( v8 > 0 )
          TTV_ErrorToString((unsigned int)v8);
      }
    }
    else
    {
      v6 = TTV_Stop(StopCallback, this);
      if ( v6 <= 0 )
      {
        this->mStreamState = eStreamState_StoppingStream;
      }
      else
      {
        v7 = (const char *)TTV_ErrorToString((unsigned int)v6);
        UFG::qPrintf("ERROR: twitch.tv - Error while stopping the stream: %s\n", v7);
      }
      this->mShutdownStreamingAfterStop = 1;
    }
  }
  UFG::qString::~qString(&result);
}

// File Line: 252
// RVA: 0x82460
void __fastcall Broadcaster::StreamStopped(Broadcaster *this)
{
  __int64 i; // rdi
  char **p; // rcx
  char **v4; // rcx

  for ( i = 0i64; i < 3; ++i )
    UFG::qMemoryPool::Free(&gVideoBroadcastMemoryPool, this->mAllFrameBuffers.p[i]);
  p = this->mAllFrameBuffers.p;
  if ( p )
    operator delete[](p);
  this->mAllFrameBuffers.p = 0i64;
  *(_QWORD *)&this->mAllFrameBuffers.size = 0i64;
  v4 = this->mFreeFrameBuffers.p;
  if ( v4 )
    operator delete[](v4);
  this->mFreeFrameBuffers.p = 0i64;
  *(_QWORD *)&this->mFreeFrameBuffers.size = 0i64;
  this->mStreamInfo.streamId = 0i64;
  this->mStreamState = eStreamState_ReadyToStream;
}

// File Line: 267
// RVA: 0x818B0
char __fastcall Broadcaster::FindIngestServer(Broadcaster *this)
{
  unsigned int ingestCount; // r8d
  unsigned int v2; // eax
  unsigned int v4; // ecx
  TTV_IngestList *p_mIngestList; // rbx
  TTV_IngestServer *p_mIngestServer; // r9
  TTV_IngestServer *v7; // rdx
  __int64 v8; // rax
  __int128 v9; // xmm0

  ingestCount = this->mIngestList.ingestCount;
  v2 = 0;
  v4 = ingestCount;
  if ( ingestCount )
  {
    while ( !this->mIngestList.ingestList[v2].defaultServer )
    {
      if ( ++v2 >= ingestCount )
        goto LABEL_6;
    }
    v4 = v2;
  }
LABEL_6:
  if ( v4 >= ingestCount )
    return 0;
  p_mIngestList = &this->mIngestList;
  p_mIngestServer = &this->mIngestServer;
  v7 = &this->mIngestList.ingestList[v4];
  if ( (((unsigned __int8)((_BYTE)this + 8) | (unsigned __int8)v7) & 0xF) != 0 )
  {
    memmove(&this->mIngestServer, v7, 0x201ui64);
    TTV_FreeIngestList(p_mIngestList);
    return 1;
  }
  else
  {
    v8 = 4i64;
    do
    {
      v9 = *(_OWORD *)v7->serverName;
      p_mIngestServer = (TTV_IngestServer *)((char *)p_mIngestServer + 128);
      v7 = (TTV_IngestServer *)((char *)v7 + 128);
      *(_OWORD *)&p_mIngestServer[-1].serverUrl[129] = v9;
      *(_OWORD *)&p_mIngestServer[-1].serverUrl[145] = *(_OWORD *)&v7[-1].serverUrl[145];
      *(_OWORD *)&p_mIngestServer[-1].serverUrl[161] = *(_OWORD *)&v7[-1].serverUrl[161];
      *(_OWORD *)&p_mIngestServer[-1].serverUrl[177] = *(_OWORD *)&v7[-1].serverUrl[177];
      *(_OWORD *)&p_mIngestServer[-1].serverUrl[193] = *(_OWORD *)&v7[-1].serverUrl[193];
      *(_OWORD *)&p_mIngestServer[-1].serverUrl[209] = *(_OWORD *)&v7[-1].serverUrl[209];
      *(_OWORD *)&p_mIngestServer[-1].serverUrl[225] = *(_OWORD *)&v7[-1].serverUrl[225];
      *(_OWORD *)&p_mIngestServer[-1].serverUrl[241] = *(_OWORD *)&v7[-1].serverUrl[241];
      --v8;
    }
    while ( v8 );
    p_mIngestServer->serverName[0] = v7->serverName[0];
    TTV_FreeIngestList(&this->mIngestList);
    return 1;
  }
}

// File Line: 382
// RVA: 0x81E50
void __fastcall Broadcaster::StartStreaming(
        Broadcaster *this,
        unsigned int outputWidth,
        unsigned int outputHeight,
        unsigned int targetFps)
{
  __int64 v7; // r12
  unsigned __int64 v8; // r13
  char *v9; // rax
  __int64 size; // r14
  unsigned int capacity; // edi
  unsigned int v12; // esi
  char *v13; // r15
  unsigned int v14; // edi
  unsigned __int64 v15; // rax
  char *v16; // rax
  char **v17; // rbp
  __int64 i; // r9
  __int64 v19; // r8
  char **p; // rax
  __int64 v21; // r14
  unsigned int v22; // edi
  unsigned int v23; // esi
  unsigned int v24; // edi
  unsigned __int64 v25; // rax
  char *v26; // rax
  char **v27; // rbp
  __int64 j; // r9
  __int64 v29; // r8
  char **v30; // rax
  int v31; // eax
  const char *v32; // rax
  int v33; // eax
  const char *v34; // rax
  int v35; // eax

  switch ( this->mStreamState )
  {
    case eStreamState_Uninitialized:
    case eStreamState_Initialized:
    case eStreamState_Authenticating:
    case eStreamState_Authenticated:
    case eStreamState_FindingIngestServer:
    case eStreamState_FoundIngestServer:
    case eStreamState_StartingStream:
    case eStreamState_Streaming:
    case eStreamState_StoppingStream:
    case eStreamState_Paused:
      return;
    default:
      this->mVideoParams.size = 40i64;
      this->mVideoParams.outputWidth = outputWidth;
      this->mVideoParams.outputHeight = outputHeight;
      this->mVideoParams.targetFps = targetFps;
      TTV_GetDefaultParams(&this->mVideoParams);
      this->mVideoParams.pixelFormat = TTV_PF_RGBA;
      this->mAudioParams.size = 16i64;
      this->mAudioParams.audioEnabled = 1;
      v7 = 3i64;
      v8 = 4 * outputHeight * outputWidth;
      do
      {
        v9 = UFG::qMemoryPool::Allocate(&gVideoBroadcastMemoryPool, v8, "BroadcastFrameBuffers", 0i64, 1u);
        size = this->mAllFrameBuffers.size;
        capacity = this->mAllFrameBuffers.capacity;
        v12 = size + 1;
        v13 = v9;
        if ( (int)size + 1 > capacity )
        {
          if ( capacity )
            v14 = 2 * capacity;
          else
            v14 = 1;
          for ( ; v14 < v12; v14 *= 2 )
            ;
          if ( v14 <= 2 )
            v14 = 2;
          if ( v14 - v12 > 0x10000 )
            v14 = size + 65537;
          if ( v14 != (_DWORD)size )
          {
            v15 = 8i64 * v14;
            if ( !is_mul_ok(v14, 8ui64) )
              v15 = -1i64;
            v16 = UFG::qMalloc(v15, "qArray.Add", 0i64);
            v17 = (char **)v16;
            if ( this->mAllFrameBuffers.p )
            {
              for ( i = 0i64;
                    (unsigned int)i < this->mAllFrameBuffers.size;
                    *(_QWORD *)&v16[v19 * 8] = this->mAllFrameBuffers.p[v19] )
              {
                v19 = i;
                i = (unsigned int)(i + 1);
              }
              operator delete[](this->mAllFrameBuffers.p);
            }
            this->mAllFrameBuffers.p = v17;
            this->mAllFrameBuffers.capacity = v14;
          }
        }
        p = this->mAllFrameBuffers.p;
        this->mAllFrameBuffers.size = v12;
        p[size] = v13;
        v21 = this->mFreeFrameBuffers.size;
        v22 = this->mFreeFrameBuffers.capacity;
        v23 = v21 + 1;
        if ( (int)v21 + 1 > v22 )
        {
          if ( v22 )
            v24 = 2 * v22;
          else
            v24 = 1;
          for ( ; v24 < v23; v24 *= 2 )
            ;
          if ( v24 <= 2 )
            v24 = 2;
          if ( v24 - v23 > 0x10000 )
            v24 = v21 + 65537;
          if ( v24 != (_DWORD)v21 )
          {
            v25 = 8i64 * v24;
            if ( !is_mul_ok(v24, 8ui64) )
              v25 = -1i64;
            v26 = UFG::qMalloc(v25, "qArray.Add", 0i64);
            v27 = (char **)v26;
            if ( this->mFreeFrameBuffers.p )
            {
              for ( j = 0i64;
                    (unsigned int)j < this->mFreeFrameBuffers.size;
                    *(_QWORD *)&v26[v29 * 8] = this->mFreeFrameBuffers.p[v29] )
              {
                v29 = j;
                j = (unsigned int)(j + 1);
              }
              operator delete[](this->mFreeFrameBuffers.p);
            }
            this->mFreeFrameBuffers.p = v27;
            this->mFreeFrameBuffers.capacity = v24;
          }
        }
        v30 = this->mFreeFrameBuffers.p;
        this->mFreeFrameBuffers.size = v23;
        v30[v21] = v13;
        --v7;
      }
      while ( v7 );
      v31 = TTV_Start(&this->mVideoParams, &this->mAudioParams, &this->mIngestServer, 0i64, StartCallback, this);
      if ( v31 <= 0 )
      {
        this->mStreamState = eStreamState_StartingStream;
      }
      else
      {
        v32 = (const char *)TTV_ErrorToString((unsigned int)v31);
        UFG::qPrintf("ERROR: twitch.tv - Error while starting to stream: %s\n", v32);
        if ( ((this->mStreamState - 10) & 0xFFFFFFFD) != 0 )
        {
          this->mAuthTokenSavedThisSession = 0;
          this->mAuthToken.data[0] = 0;
          if ( this->mStreamState )
          {
            this->mStreamState = eStreamState_Uninitialized;
            v35 = TTV_Shutdown();
            if ( v35 > 0 )
              TTV_ErrorToString((unsigned int)v35);
          }
        }
        else
        {
          v33 = TTV_Stop(StopCallback, this);
          if ( v33 <= 0 )
          {
            this->mStreamState = eStreamState_StoppingStream;
          }
          else
          {
            v34 = (const char *)TTV_ErrorToString((unsigned int)v33);
            UFG::qPrintf("ERROR: twitch.tv - Error while stopping the stream: %s\n", v34);
          }
          this->mShutdownStreamingAfterStop = 1;
        }
      }
      break;
  }
}

// File Line: 444
// RVA: 0x82500
void __fastcall Broadcaster::SubmitFrame(Broadcaster *this, char *rgba, unsigned int width, unsigned int height)
{
  unsigned int size; // r9d
  __int64 v6; // r10
  char *v7; // rbx
  int v8; // eax
  const char *v9; // rax
  int v10; // eax
  const char *v11; // rax
  int v12; // eax

  if ( ((this->mStreamState - 10) & 0xFFFFFFFD) == 0 )
  {
    size = this->mFreeFrameBuffers.size;
    v6 = size - 1;
    v7 = this->mFreeFrameBuffers.p[v6];
    if ( size <= 1 )
      LODWORD(v6) = 0;
    this->mFreeFrameBuffers.size = v6;
    UFG::qMemCopy(v7, rgba, 4 * this->mVideoParams.outputWidth * this->mVideoParams.outputHeight);
    v8 = TTV_SubmitVideoFrame(v7, FrameUnlockCallback, this);
    if ( v8 > 0 )
    {
      v9 = (const char *)TTV_ErrorToString((unsigned int)v8);
      UFG::qPrintf("ERROR: twitch.tv - error while submitting frame to stream: %s\n", v9);
      if ( ((this->mStreamState - 10) & 0xFFFFFFFD) != 0 )
      {
        this->mAuthTokenSavedThisSession = 0;
        this->mAuthToken.data[0] = 0;
        if ( this->mStreamState )
        {
          this->mStreamState = eStreamState_Uninitialized;
          v12 = TTV_Shutdown();
          if ( v12 > 0 )
            TTV_ErrorToString((unsigned int)v12);
        }
      }
      else
      {
        v10 = TTV_Stop(StopCallback, this);
        if ( v10 <= 0 )
        {
          this->mStreamState = eStreamState_StoppingStream;
        }
        else
        {
          v11 = (const char *)TTV_ErrorToString((unsigned int)v10);
          UFG::qPrintf("ERROR: twitch.tv - Error while stopping the stream: %s\n", v11);
        }
        this->mShutdownStreamingAfterStop = 1;
      }
    }
  }
}

// File Line: 466
// RVA: 0x82640
void __fastcall Broadcaster::Update(Broadcaster *this)
{
  int v2; // eax

  if ( this->mStreamState )
  {
    Broadcaster::FlushStreamingEvents(this);
    if ( this->mStreamState == eStreamState_ReadyToStream )
    {
      if ( this->mShutdownStreamingAfterStop )
      {
        this->mShutdownStreamingAfterStop = 0;
        this->mAuthTokenSavedThisSession = 0;
        this->mAuthToken.data[0] = 0;
        if ( this->mStreamState )
        {
          this->mStreamState = eStreamState_Uninitialized;
          v2 = TTV_Shutdown();
          if ( v2 > 0 )
            TTV_ErrorToString((unsigned int)v2);
        }
      }
      else
      {
        Broadcaster::StartStreaming(
          this,
          UFG::RenderStageFrameCapture::sWidth,
          UFG::RenderStageFrameCapture::sHeight,
          0x19u);
      }
    }
  }
}

// File Line: 657
// RVA: 0x819D0
void __fastcall Broadcaster::FlushStreamingEvents(Broadcaster *this)
{
  Broadcaster::StreamState mStreamState; // eax

  TTV_PollTasks();
  mStreamState = this->mStreamState;
  switch ( mStreamState )
  {
    case eStreamState_Authenticated:
      this->mStreamState = eStreamState_LoggingIn;
      this->mChannelInfo.size = 392i64;
      TTV_Login(&this->mAuthToken, LoginCallback, this);
      break;
    case eStreamState_LoggedIn:
      this->mStreamState = eStreamState_FindingIngestServer;
      TTV_GetIngestServers(&this->mAuthToken, IngestListCallback, this, &this->mIngestList);
      break;
    case eStreamState_FoundIngestServer:
      this->mStreamInfo.size = 24i64;
      this->mStreamState = eStreamState_ReadyToStream;
      this->mUserInfo.size = 136i64;
      this->mStreamInfo.streamId = 0i64;
      TTV_GetUserInfo();
      TTV_GetStreamInfo(&this->mAuthToken, StreamInfoDoneCallback, this, this->mUserName.mData, &this->mStreamInfo);
      break;
  }
}

