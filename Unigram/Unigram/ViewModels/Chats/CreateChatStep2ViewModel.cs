﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Telegram.Api.Aggregator;
using Telegram.Api.Services;
using Telegram.Api.Services.Cache;

namespace Unigram.ViewModels.Chats
{
    public class CreateChatStep2ViewModel : UsersSelectionViewModel
    {
        public CreateChatStep2ViewModel(IMTProtoService protoService, ICacheService cacheService, ITelegramEventAggregator aggregator)
            : base(protoService, cacheService, aggregator)
        {
        }
    }
}
