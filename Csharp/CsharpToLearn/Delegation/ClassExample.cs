using System;
using System.Collections.Generic;
using System.Text;

namespace Delegation
{
    //定义价格变化委托,事件本身就是一种特殊的委托
    public delegate void PriceChangeHandler(double rawPrice, double newPrice);
    internal class ClassExample
    {
        private double price;
        public event PriceChangeHandler PriceChange;//定义事件 
        public double Price
        {
            get { return price; }
            set
            {
                //事件发生的条件:价格发生变化
                if (price == value)
                {
                    return;
                }
                else
                {
                    double rawPrice = price;//保存原价
                    price = value;          //改变价格
                    if (PriceChange != null)
                    {
                        //事件触发
                        PriceChange(rawPrice, price);
                    }
                }
            }
        }
    }
}
