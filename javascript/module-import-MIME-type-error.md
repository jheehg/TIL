### TypeError: 'text/html' is not a valid JavaScript MIME type.

<br/>

###### vanilla js에서 모듈 import해서 사용하려면  타입 지정 해줘야 함.

###### 그럼에도 계속 오류가 난다면 <u>경로 및 파일명 또는 확장자 등</u> 다시 확인 하고 시도해보기.

```js
<script type="module">
    import cartPage from './CartPage.js';
    import productDetailPage from './ProductDetailPage.js';
    import productListPage from './ProductListPage.js';

    /* code */
</script>
```


