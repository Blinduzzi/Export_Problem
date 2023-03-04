# Export_Problem
Object-Oriented Programming laboratory problem

A distribution firm delivers to K countries. Every day the firm is in one country and the next day it can reach any other country.

In each country there are N resources. Countries can own amounts of each resource and can change the amount of resources they own through their own interactions or through interaction with the firm.

A country's own interactions are:

● Production: the country obtains X amount of a certain resource;

● Consumption: the country consumes an amount of a resource. If the country does not have enough of that resource then it will consume all of that resource and the country's happiness will decrease by the difference;

● Processing: the country consumes a quantity of one resource to obtain a quantity of another resource. If the country does not own enough of the consumed resource then processing will not take place.

As for their own interactions, the following are known:

● It is not mandatory for a country to interact with all available resources

● There will be no resource consumed in 2 different interactions by that country

● There will be no resource obtained from processing that is consumed in other processing by that country

Interactions between a country and a company are carried out by sale / purchase.

The country or firm offers money for a quantity of a resource held by the other party.

The offers to which the country has access when the company is present are:

● Buy: The firm provides a quantity of a resource. The firm owns the resource in the quantity it supplies. The country may or may not accept the offer.

● Sell: the firm demands a quantity of a resource. The country may or may not possess the resource in the required quantity. The country may or may not accept the offer.

If an offer has been accepted, the actual amount that will be exchanged between the 2 parties involved depends on the payer's money (if he cannot pay the full amount, he will receive an entire amount equal to what he can pay).

In terms of the country's interactions with the firm, they are:

● Buy: only consumption resources / only production + consumption resources / all resources

● Sell: any resources / any resources less consumption / any resources less production + consumption

All offers are made in the order in which they were received.

The base resource price is the same for all countries. The effective price of a resource depends on the amount of the resource held by the country as follows:

● Purchase price = base price - 3 - [quantity / 5] ( [] whole part).

● Sale price = base price - [quantity / 5] ( [] whole part).

The effective price will always be at least equal to 1 and will be constant over the course of a day.

Happiness of the country:

● is an integer.

● decreases for each incomplete consumption interaction with the missing amount (ex: the country wants to consume 5 FISH, but only has 3 FISH, so it loses 2 happiness).

● increases by 5 at the end of each day.

● at the end of the day, (after increasing by 5 points) if happiness is strictly greater than 100, it becomes 100

● at the end of the day, (after increasing by 5 points) if happiness is strictly less than 50, it becomes 50

● happiness (F) proportionally influences the amount (C) of resources / money obtained daily according to the formula [C * F / 100] ( [] integer part).

Each day, for each country, the following actions are performed in this order:

1. The country gets money from taxes.

2. If the company is located in the country, purchase offers are resolved.

3. All productions are carried out.

4. All processing is carried out.

5. All consumption is achieved.

6. If the company is located in the country, sales offers are resolved.

Before the first day, the firm has B money and no resources.

Before the first day, each country has 0 money and no resources. Also, each country has 100 happiness.

Simulate the first D days and display at the end of each day the country information.

 

Input data

N the number of resources

the names of the N resources

the price of N

B the initial amount of money of the firm.

K the number of countries.

the K countries in the form:

On the first line NAME_COUNTRY MONEY_TAXES C_BUY *** C_SELLING ***, representing the name of the country, the money obtained daily from taxes, the buying behavior and the selling behavior.



*** C_BUY is one of {CONSUMPTION, PRODUCTION, ALL} (buys only resources for consumption, only resources for consumption + processing, or buys everything offered).

*** C_SALES is one of {ANY, NO_CONSUMPTION, NO_PRODUCTION} (sell anything, anything minus consumption resources, anything minus consumption + processing resources).



On the next line N_PRODUCTIE, the number of production interactions.

Following are N_PRODUCTION lines describing the production interactions for the country in the form:

RESOURCE_OBTAINED QUANTITY_OBTAINED

On the next line N_PROCESSING, the number of processing interactions.

Following are N_PROCESSING lines describing the processing interactions for the country in the form:

RESOURCE_CONSUMED QUANTITY_CONSUMED RESOURCE_OBTAINED

QUANTITY_OBTAINED

On the next line N_CONSUM , the number of consumption interactions.

Following are N_CONSUM lines describing consumption interactions for the country in the form:

RESOURCE_CONSUMED QUANTITY_CONSUMED

On the next line D, the number of days to be simulated.

The following describes the D days, in the form:

On the first line: COUNTRY_NAME, the country where the company was located on that day.

On the next N_BUY the number of purchase offers of the company.

N_PURCHASE follows lines that describe purchase offers in the form of RESOURCE QUANTITY

On the following N_SALES the number of sales offers of the company.

N_SALES are followed by lines that describe sales offers in the form of RESOURCE QUANTITY

 

Output data

At the end of each day, information about all countries, in the order in which they were given, as follows:

on the first line, the name of the country, the happiness and the amount of money the country has.

On the following lines, in alphabetical order of resources, the name of the resource and the quantity held only if the country owns that resource (has at least 1 quantity of it). Show one free row after each country. Display form:

NAME_COUNTRY HAPPINESS_COUNTRY MONEY_COUNTRY

RESOURCE_HOLD_1 QUANTITY_RESOURCE_1

…

RESOURCE_HOLD_K QUANTITY_RESOURCE_K



Example:

Input data:

5

WOOD STONE CLAY IRON FOOD

10 10 10 10 10

100

2

ROMANIA 30 CONSUMPTION WITHOUT_CONSUMPTION

2

FOOD 11

STONE 3

1

STONE 5 IRON 2

2

FOOD 10

WOOD 9

BULGARIA 10 ANY PRODUCTION

2

WOOD 10

CLAY 10

1

STONE 5 IRON 2

1

FOOD 9

5

ROMANIA

0

0

ROMANIA

0

0

ROMANIA

0

0

ROMANIA

0

0

ROMANIA

0

0



Output data:

ROMANIA 96 30

FOOD 1

STONE 3



BULGARIA 96 10

CLAY 10

WOOD 10



ROMANIA 92 58

IRON 1

FOOD 1



BULGARIA 92 19

CLAY 19

WOOD 19



ROMANIA 88 85

IRON 1

FOOD 1

STONE 2



BULGARIA 88 28

CLAY 28

WOOD 28



ROMANIA 84 111

IRON 1

STONE 4



BULGARIA 84 36

CLAY 36

WOOD 36



ROMANIA 79 136

IRON 2

STONE 1



BULGARIA 80 44

CLAY 44

WOOD 44
