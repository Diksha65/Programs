//group transactions by currency
//Java 7
Map<currency, List<Transaction>> transactionsByCurrency = new HashMap()
for(Transaction transaction : transactions) {
    Currency currency = transaction.getCurrency();
    List<Transaction> transactionForCurrency = transactionsByCurrency.get(currency);
    if(transactionForCurrency == null) {
        transactionForCurrency = new ArrayList<>();
        transactionsByCurrency.put(currency, transactionForCurrency);
    }
    transactionForCurrency.add(transaction);
}

//Java 8
Map<Currency, List<Transaction>> transactionsByCurrency = transactions.stream()
                                                            .collect(groupingBy(Transaction::getCurrency));

