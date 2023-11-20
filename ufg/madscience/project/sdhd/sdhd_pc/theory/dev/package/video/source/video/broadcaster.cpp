// File Line: 13
// RVA: 0x1457700
__int64 dynamic_initializer_for__gVideoBroadcastMemoryPool__()
{
  UFG::qMemoryPool::qMemoryPool(&gVideoBroadcastMemoryPool);
  return atexit(dynamic_atexit_destructor_for__gVideoBroadcastMemoryPool__);
}

// File Line: 38
// RVA: 0x81CB0
void __fastcall LoginCallback(__int64 result, void *userData)
{
  _DWORD *v2; // rbx
  __int64 v3; // rax
  int v4; // eax
  unsigned int v5; // eax
  __int64 v6; // rax
  unsigned int v7; // eax

  v2 = userData;
  if ( (signed int)result > 0 )
  {
    v3 = TTV_ErrorToString(result);
    UFG::qPrintf("ERROR: twitch.tv - LoginCallback got failure: %s. Shutting down streaming...\n", v3);
    v4 = v2[468];
    *((_BYTE *)v2 + 1877) = 1;
    if ( (v4 - 10) & 0xFFFFFFFD )
    {
      *((_BYTE *)v2 + 1876) = 0;
      *((_BYTE *)v2 + 80) = 0;
      if ( v2[468] )
      {
        v2[468] = 0;
        v7 = TTV_Shutdown();
        if ( (signed int)v7 > 0 )
          TTV_ErrorToString(v7);
      }
    }
    else
    {
      v5 = TTV_Stop(StopCallback, v2);
      if ( (signed int)v5 <= 0 )
      {
        v2[468] = 11;
      }
      else
      {
        v6 = TTV_ErrorToString(v5);
        UFG::qPrintf("ERROR: twitch.tv - Error while stopping the stream: %s\n", v6);
      }
      *((_BYTE *)v2 + 1878) = 1;
    }
  }
  else
  {
    *((_DWORD *)userData + 468) = 5;
  }
}

// File Line: 59
// RVA: 0x81C50
void __fastcall IngestListCallback(__int64 result, void *userData)
{
  _DWORD *v2; // rbx
  __int64 v3; // rax

  v2 = userData;
  if ( (signed int)result > 0 )
  {
    v3 = TTV_ErrorToString(result);
    UFG::qPrintf("ERROR: twitch.tv - IngestListCallback got failure: %s\n", v3);
  }
  else if ( Broadcaster::FindIngestServer((Broadcaster *)userData) )
  {
    v2[468] = 7;
  }
}

// File Line: 77
// RVA: 0x81D80
void __fastcall StartCallback(__int64 result, void *userData)
{
  _BYTE *v2; // rbx
  __int64 v3; // rax
  unsigned int v4; // eax
  __int64 v5; // rax
  unsigned int v6; // eax

  v2 = userData;
  if ( (signed int)result <= 0 )
  {
    Broadcaster::StreamStarted((Broadcaster *)userData);
  }
  else
  {
    v3 = TTV_ErrorToString(result);
    UFG::qPrintf(0i64, "ERROR: twitch.tv - Error while starting to stream: %s\n", v3);
    if ( (*((_DWORD *)v2 + 468) - 10) & 0xFFFFFFFD )
    {
      v2[1876] = 0;
      v2[80] = 0;
      if ( *((_DWORD *)v2 + 468) )
      {
        *((_DWORD *)v2 + 468) = 0;
        v6 = TTV_Shutdown();
        if ( (signed int)v6 > 0 )
          TTV_ErrorToString(v6);
      }
    }
    else
    {
      v4 = TTV_Stop(StopCallback, v2);
      if ( (signed int)v4 <= 0 )
      {
        *((_DWORD *)v2 + 468) = 11;
      }
      else
      {
        v5 = TTV_ErrorToString(v4);
        UFG::qPrintf("ERROR: twitch.tv - Error while stopping the stream: %s\n", v5);
      }
      v2[1878] = 1;
    }
  }
}

// File Line: 92
// RVA: 0x82240
void __fastcall StopCallback(__int64 result, void *userData)
{
  __int64 v2; // rax

  if ( (signed int)result <= 0 )
  {
    Broadcaster::StreamStopped((Broadcaster *)userData);
  }
  else
  {
    v2 = TTV_ErrorToString(result);
    UFG::qPrintf("ERROR: twitch.tv - Error while stopping the stream: %s\n", v2);
  }
}

// File Line: 109
// RVA: 0x826D0
void __fastcall UserInfoDoneCallback(__int64 result, void *__formal)
{
  __int64 v2; // rax

  if ( (signed int)result > 0 )
  {
    v2 = TTV_ErrorToString(result);
    UFG::qPrintf("ERROR: twitch.tv - UserInfoDoneCallback got failure: %s\n", v2);
  }
}

// File Line: 121
// RVA: 0x82270
void __fastcall StreamInfoDoneCallback(__int64 result, void *__formal)
{
  __int64 v2; // rax

  if ( (signed int)result > 0 && (_DWORD)result != 37 )
  {
    v2 = TTV_ErrorToString(result);
    UFG::qPrintf("ERROR: twitch.tv - StreamInfoDoneCallback got failure: %s\n", v2);
  }
}

// File Line: 153
// RVA: 0x81B20
void __fastcall FrameUnlockCallback(const char *_buffer, void *userData)
{
  Broadcaster::FreeBuffer((Broadcaster *)userData, (char *)_buffer);
}

// File Line: 165
// RVA: 0x81850
void __fastcall Broadcaster::Broadcaster(Broadcaster *this)
{
  Broadcaster *v1; // rbx

  v1 = this;
  UFG::qString::qString(&this->mUserName);
  UFG::qString::qString(&v1->mPassword);
  v1->mAllFrameBuffers.p = 0i64;
  *(_QWORD *)&v1->mAllFrameBuffers.size = 0i64;
  v1->mFreeFrameBuffers.p = 0i64;
  *(_QWORD *)&v1->mFreeFrameBuffers.size = 0i64;
  v1->mStreamState = 0;
  *(_WORD *)&v1->mAuthTokenSavedThisSession = 0;
  v1->mShutdownStreamingAfterStop = 0;
}

// File Line: 222
// RVA: 0x81B30
void __fastcall Broadcaster::FreeBuffer(Broadcaster *this, char *buffer)
{
  UFG::qArray<UFG::qReflectInventoryBase *,0> *v2; // rdi
  char *v3; // rbp
  __int64 v4; // rsi
  unsigned int v5; // edx
  unsigned int v6; // ebx
  unsigned int v7; // edx
  UFG::qReflectInventoryBase **v8; // rax

  v2 = (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&this->mFreeFrameBuffers;
  v3 = buffer;
  v4 = this->mFreeFrameBuffers.size;
  v5 = this->mFreeFrameBuffers.capacity;
  v6 = v4 + 1;
  if ( (signed int)v4 + 1 > v5 )
  {
    if ( v5 )
      v7 = 2 * v5;
    else
      v7 = 1;
    for ( ; v7 < v6; v7 *= 2 )
      ;
    if ( v7 <= 2 )
      v7 = 2;
    if ( v7 - v6 > 0x10000 )
      v7 = v4 + 65537;
    UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(v2, v7, "qArray.Add");
  }
  v8 = v2->p;
  v2->size = v6;
  v8[v4] = (UFG::qReflectInventoryBase *)v3;
}

// File Line: 229
// RVA: 0x822A0
void __fastcall Broadcaster::StreamStarted(Broadcaster *this)
{
  Broadcaster *v1; // rbx
  _FILETIME v2; // rax
  float v3; // xmm0_4
  unsigned int v4; // eax
  __int64 v5; // rax
  unsigned int v6; // eax
  __int64 v7; // rax
  unsigned int v8; // eax
  __int64 v9; // [rsp+20h] [rbp-68h]
  __int64 v10; // [rsp+28h] [rbp-60h]
  __int64 v11; // [rsp+30h] [rbp-58h]
  _QWORD v12[2]; // [rsp+38h] [rbp-50h]
  UFG::qDateTime date_time; // [rsp+48h] [rbp-40h]
  UFG::qString result; // [rsp+58h] [rbp-30h]

  v1 = this;
  this->mStreamTimeStartTicks = UFG::qGetTicks();
  v2 = UFG::qGetSystemTime();
  UFG::qConvertSystemTimeToDateTime(&date_time, *(_QWORD *)&v2);
  LODWORD(v12[0]) = date_time.mSecond;
  LODWORD(v11) = date_time.mMinute;
  LODWORD(v10) = date_time.mHour;
  LODWORD(v9) = date_time.mYear;
  UFG::qString::FormatEx(
    &result,
    "%02d/%02d/%04d, %02d:%02d:%02d",
    date_time.mDay,
    date_time.mMonth,
    v9,
    v10,
    v11,
    v12[0],
    -2i64);
  v1->mStreamInfoForSetting.size = 520i64;
  v3 = FLOAT_255_0;
  if ( (float)result.mLength <= 255.0 )
    v3 = (float)result.mLength;
  UFG::qMemCopy(v1->mStreamInfoForSetting.streamTitle, result.mData, (signed int)v3);
  UFG::qMemCopy(v1->mStreamInfoForSetting.gameName, "UFG", 3u);
  v4 = TTV_SetStreamInfo(&v1->mAuthToken, v1->mChannelInfo.name, &v1->mStreamInfoForSetting);
  if ( (signed int)v4 <= 0 )
  {
    v1->mStreamState = 10;
  }
  else
  {
    v5 = TTV_ErrorToString(v4);
    UFG::qPrintf(0i64, "ERROR: twitch.tv - Error while sending stream info: %s\n", v5);
    if ( (v1->mStreamState - 10) & 0xFFFFFFFD )
    {
      v1->mAuthTokenSavedThisSession = 0;
      v1->mAuthToken.data[0] = 0;
      if ( v1->mStreamState )
      {
        v1->mStreamState = 0;
        v8 = TTV_Shutdown();
        if ( (signed int)v8 > 0 )
          TTV_ErrorToString(v8);
      }
    }
    else
    {
      v6 = TTV_Stop(StopCallback, v1);
      if ( (signed int)v6 <= 0 )
      {
        v1->mStreamState = 11;
      }
      else
      {
        v7 = TTV_ErrorToString(v6);
        UFG::qPrintf("ERROR: twitch.tv - Error while stopping the stream: %s\n", v7);
      }
      v1->mShutdownStreamingAfterStop = 1;
    }
  }
  UFG::qString::~qString(&result);
}

// File Line: 252
// RVA: 0x82460
void __fastcall Broadcaster::StreamStopped(Broadcaster *this)
{
  Broadcaster *v1; // rbx
  signed __int64 v2; // rdi
  char **v3; // rcx
  char **v4; // rcx

  v1 = this;
  v2 = 0i64;
  do
  {
    UFG::qMemoryPool::Free(&gVideoBroadcastMemoryPool, v1->mAllFrameBuffers.p[v2]);
    ++v2;
  }
  while ( v2 < 3 );
  v3 = v1->mAllFrameBuffers.p;
  if ( v3 )
    operator delete[](v3);
  v1->mAllFrameBuffers.p = 0i64;
  *(_QWORD *)&v1->mAllFrameBuffers.size = 0i64;
  v4 = v1->mFreeFrameBuffers.p;
  if ( v4 )
    operator delete[](v4);
  v1->mFreeFrameBuffers.p = 0i64;
  *(_QWORD *)&v1->mFreeFrameBuffers.size = 0i64;
  v1->mStreamInfo.streamId = 0i64;
  v1->mStreamState = 8;
}

// File Line: 267
// RVA: 0x818B0
char __fastcall Broadcaster::FindIngestServer(Broadcaster *this)
{
  unsigned int v1; // er8
  unsigned int v2; // eax
  Broadcaster *v3; // r10
  unsigned int v4; // ecx
  signed __int64 v5; // rbx
  TTV_IngestServer *v6; // r9
  TTV_IngestServer *v7; // rdx
  signed __int64 v8; // rax
  __int128 v9; // xmm0
  char result; // al

  v1 = this->mIngestList.ingestCount;
  v2 = 0;
  v3 = this;
  v4 = v1;
  if ( v1 )
  {
    while ( !v3->mIngestList.ingestList[v2].defaultServer )
    {
      if ( ++v2 >= v1 )
        goto LABEL_6;
    }
    v4 = v2;
  }
LABEL_6:
  if ( v4 >= v1 )
    return 0;
  v5 = (signed __int64)&v3->mIngestList;
  v6 = &v3->mIngestServer;
  v7 = &v3->mIngestList.ingestList[v4];
  if ( ((unsigned __int8)((_BYTE)v3 + 8) | (unsigned __int8)v7) & 0xF )
  {
    memmove(&v3->mIngestServer, v7, 0x201ui64);
    TTV_FreeIngestList(v5);
    result = 1;
  }
  else
  {
    v8 = 4i64;
    do
    {
      v9 = *(_OWORD *)v7->serverName;
      v6 = (TTV_IngestServer *)((char *)v6 + 128);
      v7 = (TTV_IngestServer *)((char *)v7 + 128);
      *(_OWORD *)&v6[-1].serverUrl[129] = v9;
      *(_OWORD *)&v6[-1].serverUrl[145] = *(_OWORD *)&v7[-1].serverUrl[145];
      *(_OWORD *)&v6[-1].serverUrl[161] = *(_OWORD *)&v7[-1].serverUrl[161];
      *(_OWORD *)&v6[-1].serverUrl[177] = *(_OWORD *)&v7[-1].serverUrl[177];
      *(_OWORD *)&v6[-1].serverUrl[193] = *(_OWORD *)&v7[-1].serverUrl[193];
      *(_OWORD *)&v6[-1].serverUrl[209] = *(_OWORD *)&v7[-1].serverUrl[209];
      *(_OWORD *)&v6[-1].serverUrl[225] = *(_OWORD *)&v7[-1].serverUrl[225];
      *(_OWORD *)&v6[-1].serverUrl[241] = *(_OWORD *)&v7[-1].serverUrl[241];
      --v8;
    }
    while ( v8 );
    v6->serverName[0] = v7->serverName[0];
    TTV_FreeIngestList(&v3->mIngestList);
    result = 1;
  }
  return result;
}

// File Line: 382
// RVA: 0x81E50
void __fastcall Broadcaster::StartStreaming(Broadcaster *this, unsigned int outputWidth, unsigned int outputHeight, unsigned int targetFps)
{
  unsigned int v4; // esi
  unsigned int v5; // edi
  Broadcaster *v6; // rbx
  signed __int64 v7; // r12
  unsigned __int64 v8; // r13
  char *v9; // rax
  __int64 v10; // r14
  unsigned int v11; // edi
  unsigned int v12; // esi
  char *v13; // r15
  unsigned int v14; // edi
  unsigned __int64 v15; // rax
  char *v16; // rax
  char *v17; // rbp
  signed __int64 v18; // r9
  signed __int64 v19; // r8
  char **v20; // rax
  __int64 v21; // r14
  unsigned int v22; // edi
  unsigned int v23; // esi
  unsigned int v24; // edi
  unsigned __int64 v25; // rax
  char *v26; // rax
  char *v27; // rbp
  signed __int64 v28; // r9
  signed __int64 v29; // r8
  char **v30; // rax
  unsigned int v31; // eax
  __int64 v32; // rax
  unsigned int v33; // eax
  __int64 v34; // rax
  unsigned int v35; // eax

  v4 = outputHeight;
  v5 = outputWidth;
  v6 = this;
  switch ( this->mStreamState )
  {
    case 0:
    case 1:
    case 2:
    case 3:
    case 6:
    case 7:
    case 9:
    case 0xA:
    case 0xB:
    case 0xC:
      return;
    default:
      this->mVideoParams.size = 40i64;
      this->mVideoParams.outputWidth = outputWidth;
      this->mVideoParams.outputHeight = outputHeight;
      this->mVideoParams.targetFps = targetFps;
      TTV_GetDefaultParams(&this->mVideoParams);
      v6->mVideoParams.pixelFormat = 33619971;
      v6->mAudioParams.size = 16i64;
      v6->mAudioParams.audioEnabled = 1;
      v7 = 3i64;
      v8 = 4 * v4 * v5;
      do
      {
        v9 = UFG::qMemoryPool::Allocate(&gVideoBroadcastMemoryPool, v8, "BroadcastFrameBuffers", 0i64, 1u);
        v10 = v6->mAllFrameBuffers.size;
        v11 = v6->mAllFrameBuffers.capacity;
        v12 = v10 + 1;
        v13 = v9;
        if ( (signed int)v10 + 1 > v11 )
        {
          if ( v11 )
            v14 = 2 * v11;
          else
            v14 = 1;
          for ( ; v14 < v12; v14 *= 2 )
            ;
          if ( v14 <= 2 )
            v14 = 2;
          if ( v14 - v12 > 0x10000 )
            v14 = v10 + 65537;
          if ( v14 != (_DWORD)v10 )
          {
            v15 = 8i64 * v14;
            if ( !is_mul_ok(v14, 8ui64) )
              v15 = -1i64;
            v16 = UFG::qMalloc(v15, "qArray.Add", 0i64);
            v17 = v16;
            if ( v6->mAllFrameBuffers.p )
            {
              v18 = 0i64;
              if ( v6->mAllFrameBuffers.size )
              {
                do
                {
                  v19 = v18;
                  v18 = (unsigned int)(v18 + 1);
                  *(_QWORD *)&v16[v19 * 8] = v6->mAllFrameBuffers.p[v19];
                }
                while ( (unsigned int)v18 < v6->mAllFrameBuffers.size );
              }
              operator delete[](v6->mAllFrameBuffers.p);
            }
            v6->mAllFrameBuffers.p = (char **)v17;
            v6->mAllFrameBuffers.capacity = v14;
          }
        }
        v20 = v6->mAllFrameBuffers.p;
        v6->mAllFrameBuffers.size = v12;
        v20[v10] = v13;
        v21 = v6->mFreeFrameBuffers.size;
        v22 = v6->mFreeFrameBuffers.capacity;
        v23 = v21 + 1;
        if ( (signed int)v21 + 1 > v22 )
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
            v27 = v26;
            if ( v6->mFreeFrameBuffers.p )
            {
              v28 = 0i64;
              if ( v6->mFreeFrameBuffers.size )
              {
                do
                {
                  v29 = v28;
                  v28 = (unsigned int)(v28 + 1);
                  *(_QWORD *)&v26[v29 * 8] = v6->mFreeFrameBuffers.p[v29];
                }
                while ( (unsigned int)v28 < v6->mFreeFrameBuffers.size );
              }
              operator delete[](v6->mFreeFrameBuffers.p);
            }
            v6->mFreeFrameBuffers.p = (char **)v27;
            v6->mFreeFrameBuffers.capacity = v24;
          }
        }
        v30 = v6->mFreeFrameBuffers.p;
        v6->mFreeFrameBuffers.size = v23;
        v30[v21] = v13;
        --v7;
      }
      while ( v7 );
      v31 = TTV_Start(&v6->mVideoParams, &v6->mAudioParams, &v6->mIngestServer, 0i64, StartCallback, v6);
      if ( (signed int)v31 <= 0 )
      {
        v6->mStreamState = 9;
      }
      else
      {
        v32 = TTV_ErrorToString(v31);
        UFG::qPrintf("ERROR: twitch.tv - Error while starting to stream: %s\n", v32);
        if ( (v6->mStreamState - 10) & 0xFFFFFFFD )
        {
          v6->mAuthTokenSavedThisSession = 0;
          v6->mAuthToken.data[0] = 0;
          if ( v6->mStreamState )
          {
            v6->mStreamState = 0;
            v35 = TTV_Shutdown();
            if ( (signed int)v35 > 0 )
              TTV_ErrorToString(v35);
          }
        }
        else
        {
          v33 = TTV_Stop(StopCallback, v6);
          if ( (signed int)v33 <= 0 )
          {
            v6->mStreamState = 11;
          }
          else
          {
            v34 = TTV_ErrorToString(v33);
            UFG::qPrintf("ERROR: twitch.tv - Error while stopping the stream: %s\n", v34);
          }
          v6->mShutdownStreamingAfterStop = 1;
        }
      }
      break;
  }
}

// File Line: 444
// RVA: 0x82500
void __fastcall Broadcaster::SubmitFrame(Broadcaster *this, char *rgba, unsigned int width, unsigned int height)
{
  Broadcaster *v4; // rdi
  unsigned int v5; // er9
  __int64 v6; // r10
  char *v7; // rbx
  unsigned int v8; // eax
  __int64 v9; // rax
  unsigned int v10; // eax
  __int64 v11; // rax
  unsigned int v12; // eax

  v4 = this;
  if ( !((this->mStreamState - 10) & 0xFFFFFFFD) )
  {
    v5 = this->mFreeFrameBuffers.size;
    v6 = v5 - 1;
    v7 = this->mFreeFrameBuffers.p[v6];
    if ( v5 <= 1 )
      LODWORD(v6) = 0;
    this->mFreeFrameBuffers.size = v6;
    UFG::qMemCopy(v7, rgba, 4 * this->mVideoParams.outputWidth * this->mVideoParams.outputHeight);
    v8 = TTV_SubmitVideoFrame(v7, FrameUnlockCallback, v4);
    if ( (signed int)v8 > 0 )
    {
      v9 = TTV_ErrorToString(v8);
      UFG::qPrintf("ERROR: twitch.tv - error while submitting frame to stream: %s\n", v9);
      if ( (v4->mStreamState - 10) & 0xFFFFFFFD )
      {
        v4->mAuthTokenSavedThisSession = 0;
        v4->mAuthToken.data[0] = 0;
        if ( v4->mStreamState )
        {
          v4->mStreamState = 0;
          v12 = TTV_Shutdown();
          if ( (signed int)v12 > 0 )
            TTV_ErrorToString(v12);
        }
      }
      else
      {
        v10 = TTV_Stop(StopCallback, v4);
        if ( (signed int)v10 <= 0 )
        {
          v4->mStreamState = 11;
        }
        else
        {
          v11 = TTV_ErrorToString(v10);
          UFG::qPrintf("ERROR: twitch.tv - Error while stopping the stream: %s\n", v11);
        }
        v4->mShutdownStreamingAfterStop = 1;
      }
    }
  }
}

// File Line: 466
// RVA: 0x82640
void __fastcall Broadcaster::Update(Broadcaster *this)
{
  Broadcaster *v1; // rbx
  unsigned int v2; // eax

  v1 = this;
  if ( this->mStreamState )
  {
    Broadcaster::FlushStreamingEvents(this);
    if ( v1->mStreamState == 8 )
    {
      if ( v1->mShutdownStreamingAfterStop )
      {
        v1->mShutdownStreamingAfterStop = 0;
        v1->mAuthTokenSavedThisSession = 0;
        v1->mAuthToken.data[0] = 0;
        if ( v1->mStreamState )
        {
          v1->mStreamState = 0;
          v2 = TTV_Shutdown();
          if ( (signed int)v2 > 0 )
            TTV_ErrorToString(v2);
        }
      }
      else
      {
        Broadcaster::StartStreaming(
          v1,
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
  Broadcaster *v1; // rsi
  Broadcaster::StreamState v2; // eax

  v1 = this;
  TTV_PollTasks();
  v2 = v1->mStreamState;
  switch ( v2 )
  {
    case 3:
      v1->mStreamState = 4;
      v1->mChannelInfo.size = 392i64;
      TTV_Login(&v1->mAuthToken, LoginCallback, v1);
      break;
    case 5:
      v1->mStreamState = 6;
      TTV_GetIngestServers(&v1->mAuthToken, IngestListCallback, v1, &v1->mIngestList);
      break;
    case 7:
      v1->mStreamInfo.size = 24i64;
      v1->mStreamState = 8;
      v1->mUserInfo.size = 136i64;
      v1->mStreamInfo.streamId = 0i64;
      TTV_GetUserInfo();
      TTV_GetStreamInfo(&v1->mAuthToken, StreamInfoDoneCallback, v1, v1->mUserName.mData, &v1->mStreamInfo);
      break;
  }
}

