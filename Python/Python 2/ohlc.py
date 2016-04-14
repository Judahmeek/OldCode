'''
Given the following parameters:
times: a list of unix timestamps in ascending order, one for each stock transaction
title: a list of strings representing the company whose stock is being transacted
side: a list of strings stating whether the transaction is a sale or a purchase
price: a list of numerics representing the unit price of the stock transaction
size: a list of integers representing the number of shares sold in each transaction

return: a list of lists, where each child list contains a date of one of the unix timestamps,
a company title (only of a company traded on that date), and the open, high, low,
and close stock price of the company for that date.
Where: the child lists are ordered by date and lexigraphical order of company title
'''
import datetime
import operator

def ohlc(times, title, side, price, size):
    dt = datetime.datetime
    stream = zip(times, title, side, price, size)
    ticker = {}
    for tick in stream:
        date = str(dt.fromtimestamp(tick[0]).date())
        key = date + tick[1]
        if key in ticker:
            value = ticker[key]
            ticker[key][3:] = [max(value[3], tick[3]), min(value[4], tick[3]), tick[3]]
        else:
            ticker[key] = [date, tick[1], tick[3], tick[3], tick[3], tick[3]]
    for tick in ticker:
        value = ticker[tick]
        ticker[tick][2:] = ["{:1.2f}".format(float(value[2])),"{:1.2f}".format(float(value[3])), "{:1.2f}".format(float(value[4])), "{:1.2f}".format(float(value[5]))]
    return sorted(ticker.values(), key=operator.itemgetter(0,1))

timestamp = [1450625399, 1450625400, 1450625500, 
             1450625550, 1451644200, 1451690100, 1451691000]
instrument = ["HPQ", "HPQ", "HPQ", "HPQ", "AAPL", "HPQ", "GOOG"]
side = ["sell", "buy", "buy", "sell", "buy", "buy", "buy"]
price = [10, 20.3, 35.5, 8.65, 20, 10, 100.35]
size = [10, 1, 2, 3, 5, 1, 10]
dailyOHLC(timestamp, instrument, side, price, size)
